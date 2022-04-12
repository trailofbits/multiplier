
#pragma once

#include <map>
#include <memory>
#include <multiplier/Action.h>
#include <multiplier/RPC.capnp.h>
#include <multiplier/API.h>
#include <multiplier/Weggli.h>
#include <multiplier/Re2.h>

#include <unordered_map>

#include "Context.h"

namespace indexer {

class RE2Action final : public mx::Action {
 private:
  const std::shared_ptr<SearchingContext> context;

  const mx::ReExpr regex;

  std::string file_contents;
  std::map<unsigned, unsigned> eol_offset_to_line_num;

  void FillFileContents(mx::FileId);

 public:
  virtual ~RE2Action(void);

  RE2Action(std::shared_ptr<SearchingContext> context_,
               std::string_view regex_string, bool is_cpp);

  void QuerySyntaxInFile(mx::FileId file_id);

  // Build and index the AST.
  void Run(mx::Executor exe, mx::WorkerId worker_id) final;
};


} //namespace search

