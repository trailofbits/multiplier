// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Re2.h"

#include "File.h"
#include "Fragment.h"

namespace mx {

RegexQueryResultImpl::~RegexQueryResultImpl(void) noexcept {}

RegexQueryResultImpl::RegexQueryResultImpl(
    std::string syntax_, EntityProvider::Ptr ep_, Response response)
    : pattern(std::move(syntax_)),
      ep(std::move(ep_)),
      re(pattern) {
  for (rpc::RegexMatch::Reader entry : response.getMatches()) {
    const FileId file_id = entry.getFileId();
    files.emplace_back().first = file_id;
    const FragmentId frag_id = entry.getFragmentId();
    fragments.emplace_back().first = frag_id;
    matches.emplace_back(file_id, frag_id);
  }
}

FragmentImpl::Ptr RegexQueryResultImpl::GetFragmentAtIndex(unsigned index) const {
  auto &entry = fragments[index];
  auto frag = entry.second.lock();
  if (!frag) {
    frag = ep->FragmentFor(ep, entry.first);
    entry.second = frag;
  }
  return frag;
}

FileImpl::Ptr RegexQueryResultImpl::GetFileAtIndex(unsigned index) const {
  auto &entry = files[index];
  auto file = entry.second.lock();
  if (!file) {
    file = ep->FileFor(ep, entry.first);
    entry.second = file;
  }
  return file;
}

EntityId RegexQueryResultImpl::EntityContainingOffset(unsigned offset) const {
  auto it = offset_to_token.upper_bound(offset);
  if (it != offset_to_token.end()) {
    return it->second;
  } else {
    return kInvalidEntityId;
  }
}

void RegexQueryResultImpl::GetUnparsedTokens(TokenSubstitutionList nodes) const {
  for (auto node : nodes) {
    if (std::holds_alternative<Token>(node)) {
      auto tok = std::get<Token>(node);
      auto tok_data = tok.data();

      // Skip empty tokens and whitespace.
      if (tok_data.empty() || tok.kind() == TokenKind::WHITESPACE) {
        continue;
      }

      fragment_buffer.insert(fragment_buffer.end(),
                             tok_data.begin(), tok_data.end());
      offset_to_token.emplace(
          static_cast<unsigned>(fragment_buffer.size()),
          tok.id());
      fragment_buffer.push_back(' ');

    } else {
      auto sub = std::get<mx::TokenSubstitution>(node);
      GetUnparsedTokens(sub.before());
    }
  }
}

void RegexQueryResultImpl::GetFileContents(File file) const {
  offset_to_token.clear();
  for (auto &tok : Token::in(file)) {
    auto tok_data = tok.data();
    file_buffer.insert(file_buffer.end(),
                       tok_data.begin(), tok_data.end());
    offset_to_token.emplace(
        static_cast<unsigned>(file_buffer.size()),
        tok.id());
  }
}

void RegexMatchIterator::Advance(void) {
  while (index < num_matches) {
    auto frag = impl->GetFragmentAtIndex(index);
    auto file = impl->GetFileAtIndex(index);
    // if the match is neither a fragment or file, continue
    // to next index.
    // TODO(kumarak) : file should never be null. Should avoid check??
    if (frag == nullptr || file == nullptr) {
      ++index;
      continue;
    }

    // Do the regex search on fragments token first. Only move looking
    // to file if there is no fragment match. It means the match is in
    // comments that are not part of fragments.
    if (frag) {
      if (impl->fragment_buffer_id != frag->id) {
        impl->next_regex_match = 0u;
        impl->regex_matches.clear();
        impl->fragment_buffer.clear();
        impl->fragment_buffer_id = frag->id;
        impl->GetUnparsedTokens(Fragment(frag).substitutions());
        impl->re.ForEachMatch(
            impl->fragment_buffer,
            [impl = impl.get()] (const std::string &match,
                unsigned begin, unsigned end) {
          impl->regex_matches.emplace_back(match, begin, end);
          return true;
        });
      }

    } else if (file) {
      // We fallback to file only if there are no fragments match

      if (impl->file_buffer_id != file->id) {
        impl->next_regex_match = 0u;
        impl->regex_matches.clear();
        impl->offset_to_token.clear();
        impl->file_buffer.clear();
        impl->file_buffer_id = file->id;
        impl->GetFileContents(File(file));
        impl->re.ForEachMatch(
            impl->file_buffer,
            [impl = impl.get()] (const std::string &match,
                unsigned begin, unsigned end) {
          impl->regex_matches.emplace_back(match, begin, end);
          return true;
        });
      }
    }

    auto next_match = impl->next_regex_match++;
    if (next_match >= impl->regex_matches.size()) {
      ++index;
      continue;
    }

    auto [match, begin_offset, end_offset] = impl->regex_matches[next_match];
    if (frag) {
      // If the regex match happens with the unparsed token of the fragment,
      // It will have the token offset in fragments. Get the token range
      // TODO (kumarak): Is it possible to get the token range from file id
      TokenRange range = frag->TokenRangeFor(frag,
                                  impl->EntityContainingOffset(begin_offset),
                                  impl->EntityContainingOffset(end_offset));

      std::unordered_map<std::string, TokenRange> pattern_matches;
      for (const auto &[match, begin, end] : impl->regex_matches) {
        pattern_matches.emplace(
            match,
            frag->TokenRangeFor(
                frag,
                impl->EntityContainingOffset(begin),
                impl->EntityContainingOffset(end)));
      }

      result.reset();
      result.emplace(frag, file, std::move(range.impl),
                     range.index, range.num_tokens, pattern_matches);

    } else if (file) {
      // Get the token range if the matches are only in file
      auto reader = file->TokenReader(file);
      auto range = TokenRange(reader, begin_offset, end_offset);

      std::unordered_map<std::string, TokenRange> pattern_matches;
      for (const auto &[match, begin, end] : impl->regex_matches) {
        pattern_matches.emplace(
            match, TokenRange(reader, begin, end));
      }

      result.reset();
      result.emplace(frag, file, std::move(range.impl),
                     range.index, range.num_tokens, pattern_matches);

    }
    return;
  }
}

RegexMatch::RegexMatch(
    std::shared_ptr<const FragmentImpl> frag_,
    std::shared_ptr<const FileImpl> file_,
    std::shared_ptr<const TokenReader> impl_,
    unsigned index_, unsigned num_tokens_,
    std::unordered_map<std::string, TokenRange> variable_matches_)
    : TokenRange(std::move(impl_), index_, num_tokens_),
      frag(std::move(frag_)), file(std::move(file_)),
      variable_matches(std::move(variable_matches_)) {}

std::optional<TokenRange> RegexMatch::MatchFor(const std::string &var) const {
  auto it = variable_matches.find(var);
  if (it != variable_matches.end()) {
    return it->second;
  } else {
    return std::nullopt;
  }
}

// Return a list of matched variables.
std::vector<std::string> RegexMatch::MatchedVariables(void) const {
  std::vector<std::string> ret;
  for (const auto &[var, _] : variable_matches) {
    ret.emplace_back(var);
  }
  return ret;
}

RegexQueryResult::RegexQueryResult(
    std::shared_ptr<const RegexQueryResultImpl> impl_)
    : impl(std::move(impl_)),
      num_fragments(impl->fragments.size()) {}

}  // namespace mx
