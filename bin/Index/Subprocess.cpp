// Copyright (c) 2019-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.
#include "Subprocess.h"

#include <gflags/gflags.h>
#include <glog/logging.h>

#include <array>
#include <cstring>
#include <errno.h>
#include <fcntl.h>
#include <fstream>
#include <functional>
#include <poll.h>
#include <reproc++/drain.hpp>
#include <reproc++/reproc.hpp>
#include <sstream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

DECLARE_bool(fork_mode);
DECLARE_bool(reproc_mode);

namespace indexer {
// Execute the command specified in `args` with the ability to feed the
// command input and capture output. Passing `nullptr` to any of `input`,
// `output`, or `error` is acceptable.

// Constants for timeouts
constexpr int TIMEOUT_MS = 300000;           // 5 minutes
constexpr int GRACEFUL_TERMINATION_MS = 100000; // 100ms
constexpr size_t IO_BUFFER_SIZE = 4096;      // Buffer size for read/write

// Helper to check system calls and return error codes
#define CHECK_SYSTEM_CALL(call, cleanup) \
  if ((call) == -1) {                    \
    cleanup();                           \
    return std::make_error_code(static_cast<std::errc>(errno)); \
  }

// Struct to manage a single pipe (stdin, stdout, or stderr)
struct PipeHandler {
  int fd = -1;                    // Pipe file descriptor
  bool done = false;              // Stream completion status
  std::string* buffer = nullptr;  // Output buffer (for stdout/stderr)
  const char* input_data = nullptr; // Input data (for stdin)
  size_t input_pos = 0;           // Current position (for stdin)
  size_t input_remaining = 0;     // Remaining bytes (for stdin)

  // Setup pollfd for this pipe
  void setup_poll(pollfd& pfd) const {
    pfd = {fd, static_cast<short>(buffer ? POLLIN : POLLOUT), 0};
  }

  // Handle I/O for this pipe (read for stdout/stderr, write for stdin)
  void handle_io(std::vector<pollfd>& poll_fds, size_t poll_index,
                 std::array<char, IO_BUFFER_SIZE>& buffer) {
    if (done || !(poll_fds[poll_index].revents & (POLLIN | POLLOUT | POLLHUP | POLLERR | POLLNVAL))) {
      return;
    }

    if (poll_fds[poll_index].revents & (POLLHUP | POLLERR | POLLNVAL)) {
      close(fd);
      fd = -1;
      done = true;
      poll_fds.erase(poll_fds.begin() + static_cast<std::ptrdiff_t>(poll_index));
      return;
    }

    if (this->buffer) { // Read from stdout/stderr (buffer is non-null)
      ssize_t bytes_read = read(fd, buffer.data(), buffer.size());
      if (bytes_read > 0) {
        this->buffer->append(buffer.data(), static_cast<size_t>(bytes_read));
      } else if (bytes_read == 0 || (bytes_read == -1 && errno != EAGAIN && errno != EINTR)) {
        close(fd);
        fd = -1;
        done = true;
        poll_fds.erase(poll_fds.begin() + static_cast<std::ptrdiff_t>(poll_index));
      }
    } else { // Write to stdin (buffer is null)
      ssize_t written = write(fd, input_data + input_pos, input_remaining);
      if (written > 0) {
        input_pos += static_cast<size_t>(written);
        input_remaining -= static_cast<size_t>(written);
        if (input_remaining == 0) {
          close(fd);
          fd = -1;
          done = true;
          poll_fds.erase(poll_fds.begin() + static_cast<std::ptrdiff_t>(poll_index));
        }
      } else if (written == 0 || (written == -1 && errno != EAGAIN && errno != EINTR)) {
        close(fd);
        fd = -1;
        done = true;
        poll_fds.erase(poll_fds.begin() + static_cast<std::ptrdiff_t>(poll_index));
      }
    }
  }
};

// Setup pipes for stdin, stdout, stderr
std::error_code setup_pipes(int stdin_pipe[2], int stdout_pipe[2], int stderr_pipe[2],
                            std::string* input, std::string* output, std::string* error,
                            std::function<void()> cleanup) {
  if (input && !input->empty()) {
    CHECK_SYSTEM_CALL(pipe(stdin_pipe), cleanup);
  }
  if (output) {
    CHECK_SYSTEM_CALL(pipe(stdout_pipe), cleanup);
  }
  if (error) {
    CHECK_SYSTEM_CALL(pipe(stderr_pipe), cleanup);
  }
  return {};
}

// Configure child process (pipe redirection, environment, exec)
void handle_child(const std::vector<std::string>& cmd,
                  const std::unordered_map<std::string, std::string>* env,
                  int stdin_pipe[2], int stdout_pipe[2], int stderr_pipe[2],
                  std::string* input, std::string* output, std::string* error) {
  try {
    // Setup stdin
    if (input && !input->empty()) {
      close(stdin_pipe[1]);
      if (dup2(stdin_pipe[0], STDIN_FILENO) == -1) _exit(1);
      close(stdin_pipe[0]);
    }

    // Setup stdout
    if (output) {
      close(stdout_pipe[0]);
      if (dup2(stdout_pipe[1], STDOUT_FILENO) == -1) _exit(1);
      close(stdout_pipe[1]);
    } else {
      int dev_null = open("/dev/null", O_WRONLY);
      if (dev_null == -1 || dup2(dev_null, STDOUT_FILENO) == -1) _exit(1);
      close(dev_null);
    }

    // Setup stderr
    if (error) {
      close(stderr_pipe[0]);
      if (dup2(stderr_pipe[1], STDERR_FILENO) == -1) _exit(1);
      close(stderr_pipe[1]);
    } else {
      int dev_null = open("/dev/null", O_WRONLY);
      if (dev_null == -1 || dup2(dev_null, STDERR_FILENO) == -1) _exit(1);
      close(dev_null);
    }

    // Setup environment variables
    if (env) {
      for (const auto& kv : *env) {
        if (setenv(kv.first.c_str(), kv.second.c_str(), 1) != 0) {
          _exit(1);
        }
      }
    }

    // Prepare arguments for execvp
    std::vector<char*> args;
    args.reserve(cmd.size() + 1);
    for (const auto& arg : cmd) {
      args.push_back(const_cast<char*>(arg.c_str()));
    }
    args.push_back(nullptr);

    execvp(cmd[0].c_str(), args.data());
    _exit(1); // execvp failed
  } catch (...) {
    _exit(1); // Catch exceptions in child
  }
}

// Handle parent process I/O (non-blocking read/write with polling)
std::error_code handle_parent_io(pid_t child_pid, int stdin_pipe[2], int stdout_pipe[2],
                                 int stderr_pipe[2], std::string* input,
                                 std::string* output, std::string* error,
                                 std::function<void()> cleanup) {
  // Close unused pipe ends
  if (stdin_pipe[0] != -1) close(stdin_pipe[0]);
  if (stdout_pipe[1] != -1) close(stdout_pipe[1]);
  if (stderr_pipe[1] != -1) close(stderr_pipe[1]);

  // Set pipes to non-blocking
  if (input && !input->empty()) {
    CHECK_SYSTEM_CALL(fcntl(stdin_pipe[1], F_SETFL, O_NONBLOCK), cleanup);
  }
  if (output) {
    CHECK_SYSTEM_CALL(fcntl(stdout_pipe[0], F_SETFL, O_NONBLOCK), cleanup);
  }
  if (error) {
    CHECK_SYSTEM_CALL(fcntl(stderr_pipe[0], F_SETFL, O_NONBLOCK), cleanup);
  }

  // Initialize pipe handlers
  std::string stdout_buf, stderr_buf;
  std::vector<PipeHandler> pipes = {
    {stdin_pipe[1], !input || input->empty(), nullptr, input ? input->data() : nullptr,
     0, input ? input->size() : 0},
    {stdout_pipe[0], !output, output ? &stdout_buf : nullptr},
    {stderr_pipe[0], !error, error ? &stderr_buf : nullptr}
  };

  // I/O buffer
  std::array<char, IO_BUFFER_SIZE> buffer;

  // Main I/O loop
  while (std::any_of(pipes.begin(), pipes.end(), [](const auto& p) { return !p.done; })) {
    std::vector<pollfd> poll_fds;
    for (const auto& pipe : pipes) {
      if (!pipe.done) {
        pollfd pfd;
        pipe.setup_poll(pfd);
        poll_fds.push_back(pfd);
      }
    }

    int poll_result = poll(poll_fds.data(), poll_fds.size(), TIMEOUT_MS);
    if (poll_result == 0) {
      kill(child_pid, SIGTERM);
      usleep(GRACEFUL_TERMINATION_MS);
      kill(child_pid, SIGKILL);
      cleanup();
      return std::make_error_code(std::errc::timed_out);
    } else if (poll_result < 0 && errno != EINTR) {
      cleanup();
      return std::make_error_code(static_cast<std::errc>(errno));
    }

    size_t poll_index = 0;
    for (size_t i = 0; i < pipes.size(); ++i) {
      if (!pipes[i].done) {
        pipes[i].handle_io(poll_fds, poll_index++, buffer);
      }
    }
  }

  // Move output buffers
  if (output) *output = std::move(stdout_buf);
  if (error) *error = std::move(stderr_buf);

  return {};
}

// Wait for child process and get exit status
std::variant<int, std::error_code> wait_for_child(pid_t child_pid) {
  int status;
  struct timespec ts;
  ts.tv_sec = TIMEOUT_MS / 1000;
  ts.tv_nsec = (TIMEOUT_MS % 1000) * 1000000;

  siginfo_t info;
  int wait_result = waitid(P_PID, static_cast<id_t>(child_pid), &info, WEXITED | WNOWAIT);
  if (wait_result == -1) {
    if (errno == EINTR) {
      if (waitpid(child_pid, &status, 0) == -1) {
        return std::make_error_code(static_cast<std::errc>(errno));
      }
    } else {
      return std::make_error_code(static_cast<std::errc>(errno));
    }
  } else {
    if (waitpid(child_pid, &status, 0) == -1) {
      return std::make_error_code(static_cast<std::errc>(errno));
    }
  }

  if (WIFEXITED(status)) {
    return WEXITSTATUS(status);
  } else if (WIFSIGNALED(status)) {
    return 128 + WTERMSIG(status);
  }
  return 1; // Unknown error
}

// Detect if running inside a Docker container
bool Subprocess::IsRunningInDocker() {
  std::ifstream cgroup("/proc/self/cgroup");
  if (cgroup.is_open()) {
    std::string line;
    while (std::getline(cgroup, line)) {
      if (line.find("docker") != std::string::npos) {
        return true;
      }
    }
  }

  // Check for .dockerenv file
  std::ifstream dockerenv("/.dockerenv");
  if (dockerenv.good()) {
    return true;
  }

  return false;
}

// Execute command using fork+exec approach
std::variant<int, std::error_code>
Subprocess::ExecuteFork(const std::vector<std::string>& cmd,
                        const std::unordered_map<std::string, std::string>* env,
                        std::string* input, std::string* output, std::string* error) {
  if (cmd.empty()) {
    return std::make_error_code(std::errc::invalid_argument);
  }

  // Initialize pipes
  int stdin_pipe[2] = {-1, -1};
  int stdout_pipe[2] = {-1, -1};
  int stderr_pipe[2] = {-1, -1};

  auto cleanup_pipes = [&]() {
    for (int fd : {stdin_pipe[0], stdin_pipe[1], stdout_pipe[0],
                   stdout_pipe[1], stderr_pipe[0], stderr_pipe[1]}) {
      if (fd != -1) close(fd);
    }
  };

  // Setup pipes
  auto ec = setup_pipes(stdin_pipe, stdout_pipe, stderr_pipe, input, output, error, cleanup_pipes);
  if (ec) {
    return ec;
  }

  // Fork the process
  pid_t child_pid;
  CHECK_SYSTEM_CALL(child_pid = fork(), cleanup_pipes);

  if (child_pid == 0) {
    handle_child(cmd, env, stdin_pipe, stdout_pipe, stderr_pipe, input, output, error);
  }

  // Parent process: handle I/O
  ec = handle_parent_io(child_pid, stdin_pipe, stdout_pipe, stderr_pipe, input, output, error, cleanup_pipes);
  if (ec) {
    return ec;
  }

  // Wait for child
  return wait_for_child(child_pid);
}

// Execute function that chooses the appropriate implementation
std::variant<int, std::error_code>
Subprocess::Execute(const std::vector<std::string>& cmd,
                    const std::unordered_map<std::string, std::string>* env,
                    std::string* input, std::string* output,
                    std::string* error) {
  // Check if running in Docker and use fork+exec if so
  bool insideDocker = IsRunningInDocker();
  if (!FLAGS_reproc_mode) {
    if (insideDocker) {
      if (!FLAGS_fork_mode) {
        LOG(ERROR) << "Docker environment found. Use --fork_mode";
        _exit(1);
      }
      LOG(INFO) << "Executing fork+exec way for Docker environments" << std::endl;
      return ExecuteFork(cmd, env, input, output, error);
    }
  }

  // reproc implementation
  if (insideDocker) {
    LOG(INFO) << "Using reproc library for Docker environment" << std::endl;
  } else {
    LOG(INFO) << "Using reproc library for non-Docker environments" << std::endl;
  }
  reproc::process process;
  reproc::arguments args(cmd);
  reproc::options options;
  options.env.behavior = reproc::env::empty;
  if (env) {
    options.env.extra = reproc::env(*env);
  }

  if (input) {
    options.redirect.in.type = reproc::redirect::pipe;
  }
  if (output) {
    options.redirect.out.type = reproc::redirect::pipe;
  } else {
    options.redirect.out.type = reproc::redirect::discard;
  }
  if (error) {
    options.redirect.err.type = reproc::redirect::pipe;
  } else {
    options.redirect.err.type = reproc::redirect::discard;
  }

  std::error_code ec = process.start(args, options);
  if (ec) {
    return ec;
  }

  // Write input to the child process.
  if (input && !input->empty()) {
    size_t next_i = 0u;
    auto data = reinterpret_cast<const uint8_t *>(input->data());
    for (auto max_i = input->size(); next_i < max_i;) {
      auto [num_written_bytes, write_ec] =
          process.write(&(data[next_i]), max_i - next_i);
      if (write_ec) {
        return write_ec;
      } else {
        next_i += num_written_bytes;
      }
    }
  }

  // Drain output from the child process.
  if (output && error) {
    reproc::sink::string stdout_sink(*output);
    reproc::sink::string stderr_sink(*error);
    ec = reproc::drain(process, stdout_sink, stderr_sink);
    if (ec) {
      return ec;
    }
  } else if (output) {
    reproc::sink::string stdout_sink(*output);
    ec = reproc::drain(process, stdout_sink, reproc::sink::null);
    if (ec) {
      return ec;
    }
  } else if (error) {
    reproc::sink::string stderr_sink(*error);
    ec = reproc::drain(process, reproc::sink::null, stderr_sink);
    if (ec) {
      return ec;
    }
  }

  // Wait for completion.
  int status = 0;
  std::tie(status, ec) = process.wait(reproc::infinite);
  if (ec) {
    return ec;
  }

  return status;
}

}  // namespace indexer
