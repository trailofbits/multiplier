// Copyright (c) 2019-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
# error "TODO: Add Windows support for Subprocess invocation"
#endif

#include <multiplier/Subprocess.h>

#include <gflags/gflags.h>
#include <glog/logging.h>

#include <cctype>
#include <cerrno>
#include <csignal>
#include <fcntl.h>
#include <iterator>
#include <sstream>
#include <sys/wait.h>
#include <unistd.h>
#include <poll.h>

#include <pasta/Util/ArgumentVector.h>

namespace mx {
namespace {

class NullBuffer : public std::streambuf {
 public:
  int overflow(int c) { return c; }
};

}  // namespace

// Execute the command specified in `args` with the ability to feed the
// command input and capture output. Passing `nullptr` to any of `input`,
// `output`, or `error` is acceptable.
int Subprocess::Execute(const pasta::ArgumentVector &cmd, std::istream *input,
                        std::ostream *output, std::ostream *error) {
  enum {
    kRead = 0,
    kWrite = 1
  };

  int input_pipe[2] = {-1, -1};
  int output_pipe[2] = {-1, -1};
  int error_pipe[2] = {-1, -1};

  LOG(INFO) << "Executing command: " << cmd.Join();

  auto has_error = false;
  if (-1 == pipe(input_pipe)) {
    const auto err = errno;
    LOG(ERROR)
        << "Unable to create pipe for stdin: " << strerror(err);
    has_error = true;
  }

  if (-1 == pipe(output_pipe)) {
    const auto err = errno;
    LOG(ERROR)
        << "Unable to create pipe for stdin: " << strerror(err);
    has_error = true;
  }

  if (-1 == pipe(error_pipe)) {
    const auto err = errno;
    LOG(ERROR)
        << "Unable to create pipe for stdin: " << strerror(err);
    has_error = true;
  }

  if (has_error) {
    close(input_pipe[kRead]);
    close(input_pipe[kWrite]);
    close(output_pipe[kRead]);
    close(output_pipe[kWrite]);
    close(error_pipe[kRead]);
    close(error_pipe[kWrite]);
    return EXIT_FAILURE;
  }

  CHECK_NE(input_pipe[kRead], STDIN_FILENO);
  CHECK_NE(input_pipe[kWrite], STDIN_FILENO);
  CHECK_NE(output_pipe[kRead], STDOUT_FILENO);
  CHECK_NE(output_pipe[kWrite], STDOUT_FILENO);
  CHECK_NE(error_pipe[kRead], STDERR_FILENO);
  CHECK_NE(error_pipe[kWrite], STDERR_FILENO);

  const auto pid = fork();
  if (-1 == pid) {
    const auto err = errno;
    LOG(ERROR)
        << "Unable to launch process: " << strerror(err);
    return EXIT_FAILURE;

  } else if (!pid) {
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    errno = 0;
    while ((dup2(input_pipe[kRead], STDIN_FILENO) == -1) &&
           (errno == EINTR || errno == EAGAIN)) {}
    errno = 0;
    while ((dup2(output_pipe[kWrite], STDOUT_FILENO) == -1) &&
           (errno == EINTR || errno == EAGAIN)) {}
    errno = 0;
    while ((dup2(error_pipe[kWrite], STDERR_FILENO) == -1) &&
           (errno == EINTR || errno == EAGAIN)) {}

    close(input_pipe[kRead]);
    close(input_pipe[kWrite]);
    close(output_pipe[kRead]);
    close(output_pipe[kWrite]);
    close(error_pipe[kRead]);
    close(error_pipe[kWrite]);

    execvp(cmd[0], const_cast<char * const *>(cmd.Argv()));
    exit(EXIT_FAILURE);
  }

  close(input_pipe[kRead]);
  close(output_pipe[kWrite]);
  close(error_pipe[kWrite]);

  usleep(250000);  // 0.25s

  NullBuffer null_buff;
  std::iostream null_stream(&null_buff);
  std::string results;

  // Write input to the child process.
  if (input) {
    const auto flags = input->flags();
    *input >> std::noskipws;
    std::istream_iterator<char> it(*input);
    std::istream_iterator<char> end;
    results.assign(it, end);
    input->setf(flags);

    auto data = results.c_str();
    ssize_t offset = 0;
    ssize_t remaining = static_cast<ssize_t>(results.size());
    while (remaining) {
      const auto written = write(input_pipe[kWrite], &(data[offset]),
                                 static_cast<size_t>(remaining));
      const auto err = errno;
      if (0 < written) {
        remaining -= written;
        offset += written;
      } else if (-1 == written) {
        if (EAGAIN == err || EINTR == err) {
          continue;
        } else {  // E.g. `EPIPE`.
          break;
        }
      } else {
        break;
      }
    }
  }

  close(input_pipe[kWrite]);

  if (!output) {
    output = &null_stream;
  }
  if (!error) {
    error = &null_stream;
  }

  char buff[4096];

  auto done_output = false;
  auto done_error = false;

  while (!done_output || !done_error) {
    pollfd fds[2];
    memset(fds, 0, sizeof(fds));
    fds[0].fd = output_pipe[kRead];
    fds[0].events = POLLIN;

    fds[1].fd = error_pipe[kRead];
    fds[1].events = POLLIN;

    poll(fds, 2, -1);

    if (fds[0].revents & POLLIN) {
      const auto amount = read(output_pipe[kRead], &buff, sizeof(buff));
      const auto err = errno;
      if (0 < amount) {
        results.assign(buff, static_cast<size_t>(amount));
        *output << results;
      } else if (amount == 0 || (EAGAIN != err && EINTR != err)) {
        done_output = true;
      }
    }
    if (fds[0].revents & (POLLERR | POLLHUP| POLLNVAL)) {
      done_output = true;
    }

    if (fds[1].revents & POLLIN) {
      const auto amount = read(error_pipe[kRead], &buff, sizeof(buff));
      const auto err = errno;
      if (0 < amount) {
        results.assign(buff, static_cast<size_t>(amount));
        *error << results;
      } else if (amount == 0 || (EAGAIN != err && EINTR != err)) {
        done_error = true;
      }
    }
    if (fds[1].revents & (POLLERR | POLLHUP| POLLNVAL)) {
      done_error = true;
    }
  }

  close(error_pipe[kRead]);
  close(output_pipe[kRead]);

  int status = 0;
  while (const auto ret = waitpid(pid, &status, 0)) {
    if (false) {
#ifdef WIFEXITED
    } else if (WIFEXITED(status)) {
      return WEXITSTATUS(status);

#endif
#ifdef WIFSIGNALED
    } else if (WIFSIGNALED(status)) {
      return -WTERMSIG(status);

#endif
#ifdef WIFSTOPPED
    } else if (WIFSTOPPED(status)) {
      kill(pid, SIGCONT);
      continue;
#endif
#ifdef WIFCONTINUED
    } else if (WIFCONTINUED(status)) {
      continue;
#endif

    // This just means there's a status change; it could imply the process
    // exited or some other condition was met.
    } else if (ret == pid) {
      continue;

    } else if (ret == -1) {
      const auto err = errno;
      LOG(ERROR)
          << "Error when checking child process status: " << strerror(err);
      return EXIT_FAILURE;
    }
  }

  return EXIT_FAILURE;
}

}  // namespace mx
