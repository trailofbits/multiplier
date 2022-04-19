
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

class RegexSearchAction final : public mx::Action {
 private:
  const std::shared_ptr<SearchingContext> context;

  const mx::RegExpr regex;

  std::map<unsigned, unsigned> offset_to_line_num;

 public:
  virtual ~RegexSearchAction(void);

  RegexSearchAction(std::shared_ptr<SearchingContext> context_,
                    std::string_view pattern);

  void QueryExprInFile(mx::FileId file_id);

  // Build and index the AST.
  void Run(mx::Executor exe, mx::WorkerId worker_id) final;
};


} //namespace search

