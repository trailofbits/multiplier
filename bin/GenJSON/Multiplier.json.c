[
#define MX_BEGIN_ENUM_CLASS(ENUM, TYPE, ...) { "type": "enum", "name": #ENUM, "base": #TYPE, "entries": [
#define MX_ENUM_CLASS_ENTRY(ENUM, ENTRY, ...) #ENTRY,
#define MX_END_ENUM_CLASS(...) ""]},

#define BEGIN_ENTITY(TYPE, ENTITY) { "type": #TYPE, "name": #ENTITY, "entries": [
#define MX_BEGIN_VISIT_DECL(ENTITY, ...) BEGIN_ENTITY(decl, ENTITY)
#define MX_BEGIN_VISIT_STMT(ENTITY, ...) BEGIN_ENTITY(stmt, ENTITY)
#define MX_BEGIN_VISIT_TYPE(ENTITY, ...) BEGIN_ENTITY(type, ENTITY)
#define MX_BEGIN_VISIT_ATTR(ENTITY, ...) BEGIN_ENTITY(attr, ENTITY)
#define MX_BEGIN_VISIT_MACRO(ENTITY, ...) BEGIN_ENTITY(macro, ENTITY)
#define MX_BEGIN_VISIT_PSEUDO(ENTITY, ...) BEGIN_ENTITY(pseudo, ENTITY)

#define BEGIN_ABSTRACT_ENTITY(TYPE, ENTITY) { "type": #TYPE, "name": #ENTITY, "abstract": true, "entries": [
#define MX_BEGIN_VISIT_ABSTRACT_DECL(ENTITY, ...) BEGIN_ABSTRACT_ENTITY(decl, ENTITY)
#define MX_BEGIN_VISIT_ABSTRACT_STMT(ENTITY, ...) BEGIN_ABSTRACT_ENTITY(stmt, ENTITY)
#define MX_BEGIN_VISIT_ABSTRACT_TYPE(ENTITY, ...) BEGIN_ABSTRACT_ENTITY(type, ENTITY)
#define MX_BEGIN_VISIT_ABSTRACT_ATTR(ENTITY, ...) BEGIN_ABSTRACT_ENTITY(attr, ENTITY)
#define MX_BEGIN_VISIT_ABSTRACT_MACRO(ENTITY, ...) BEGIN_ABSTRACT_ENTITY(macro, ENTITY)

#define MX_VISIT_BOOL(IGN0, FIELD, ...) { "type": "bool", "name": #FIELD },
#define MX_VISIT_INT(IGN0, FIELD, ...) { "type": "int", "name": #FIELD },
#define MX_VISIT_TEXT(IGN0, FIELD, ...) { "type": "text", "name": #FIELD },
#define MX_VISIT_PATH(IGN0, FIELD, ...) { "type": "path", "name": #FIELD },
#define MX_VISIT_ENUM(IGN0, FIELD, IGN1, IGN2, IGN3, ENUM, ...) { "type": "enum", "name": #FIELD, "enum": #ENUM },
#define MX_VISIT_ENTITY(IGN0, FIELD, IGN1, IGN2, IGN3, ENTITY, ...) { "type": "entity", "name": #FIELD, "entity": #ENTITY },
#define MX_VISIT_PSEUDO(IGN0, FIELD, IGN1, IGN2, IGN3, ENTITY, ...) { "type": "pseudo", "name": #FIELD, "entity": #ENTITY },

#define MX_VISIT_OPTIONAL_BOOL(IGN0, FIELD, ...) { "type": "bool", "name": #FIELD, "optional": true },
#define MX_VISIT_OPTIONAL_INT(IGN0, FIELD, ...) { "type": "int", "name": #FIELD, "optional": true },
#define MX_VISIT_OPTIONAL_TEXT(IGN0, FIELD, ...) { "type": "text", "name": #FIELD, "optional": true },
#define MX_VISIT_OPTIONAL_PATH(IGN0, FIELD, ...) { "type": "path", "name": #FIELD, "optional": true },
#define MX_VISIT_OPTIONAL_ENUM(IGN0, FIELD, IGN1, IGN2, IGN3, ENUM, ...) { "type": "enum", "name": #FIELD, "enum": #ENUM, "optional": true },
#define MX_VISIT_OPTIONAL_ENTITY(IGN0, FIELD, IGN1, IGN2, IGN3, ENTITY, ...) { "type": "entity", "name": #FIELD, "entity": #ENTITY, "optional": true },
#define MX_VISIT_OPTIONAL_PSEUDO(IGN0, FIELD, IGN1, IGN2, IGN3, ENTITY, ...) { "type": "pseudo", "name": #FIELD, "entity": #ENTITY, "optional": true },

#define MX_VISIT_BOOL_LIST(IGN0, FIELD, ...) { "type": "bool", "name": #FIELD, "list": true },
#define MX_VISIT_INT_LIST(IGN0, FIELD, ...) { "type": "int", "name": #FIELD, "list": true },
#define MX_VISIT_TEXT_LIST(IGN0, FIELD, ...) { "type": "text", "name": #FIELD, "list": true },
#define MX_VISIT_PATH_LIST(IGN0, FIELD, ...) { "type": "path", "name": #FIELD, "list": true },
#define MX_VISIT_ENUM_LIST(IGN0, FIELD, IGN1, IGN2, IGN3, ENUM, ...) { "type": "enum", "name": #FIELD, "enum": #ENUM, "list": true },
#define MX_VISIT_ENTITY_LIST(IGN0, FIELD, IGN1, IGN2, IGN3, ENTITY, ...) { "type": "entity", "name": #FIELD, "entity": #ENTITY, "list": true },
#define MX_VISIT_PSEUDO_LIST(IGN0, FIELD, IGN1, IGN2, IGN3, ENTITY, ...) { "type": "pseudo", "name": #FIELD, "entity": #ENTITY, "list": true },
#define MX_VISIT_DECL_CONTEXT(IGN0, FIELD, IGN1, IGN2, IGN3, ENTITY, ...) { "type": "decl_context", "name": #FIELD, "entity": #ENTITY },

#define MX_VISIT_OPTIONAL_BOOL_LIST(IGN0, FIELD, ...) { "type": "bool", "name": #FIELD, "list": true, "optional": true },
#define MX_VISIT_OPTIONAL_INT_LIST(IGN0, FIELD, ...) { "type": "int", "name": #FIELD, "list": true, "optional": true },
#define MX_VISIT_OPTIONAL_TEXT_LIST(IGN0, FIELD, ...) { "type": "text", "name": #FIELD, "list": true, "optional": true },
#define MX_VISIT_OPTIONAL_PATH_LIST(IGN0, FIELD, ...) { "type": "path", "name": #FIELD, "list": true, "optional": true },
#define MX_VISIT_OPTIONAL_ENUM_LIST(IGN0, FIELD, IGN1, IGN2, IGN3, ENUM, ...) { "type": "enum", "name": #FIELD, "enum": #ENUM, "list": true, "optional": true },
#define MX_VISIT_OPTIONAL_ENTITY_LIST(IGN0, FIELD, IGN1, IGN2, IGN3, ENTITY, ...) { "type": "entity", "name": #FIELD, "entity": #ENTITY, "list": true, "optional": true },
#define MX_VISIT_OPTIONAL_PSEUDO_LIST(IGN0, FIELD, IGN1, IGN2, IGN3, ENTITY, ...) { "type": "pseudo", "name": #FIELD, "entity": #ENTITY, "list": true, "optional": true },

#define MX_VISIT_BASE(IGN0, BASE, ...) { "type": "base", "base": #BASE },
#define MX_VISIT_TOKEN_RANGE(IGN0, FIELD, ...) { "type": "token_range", "name": #FIELD },
#define MX_VISIT_DECL_LINK(IGN0, FIELD, ...) { "type": "decl_link", "name": #FIELD },
#define MX_VISIT_STMT_LINK(IGN0, FIELD, ...) { "type": "stmt_link", "name": #FIELD },

#define MX_END_VISIT_DECL(...) {"type": "ignore"}]},
#define MX_END_VISIT_STMT MX_END_VISIT_DECL
#define MX_END_VISIT_TYPE MX_END_VISIT_DECL
#define MX_END_VISIT_ATTR MX_END_VISIT_DECL
#define MX_END_VISIT_MACRO MX_END_VISIT_DECL
#define MX_END_VISIT_PSEUDO MX_END_VISIT_DECL
#include <multiplier/Visitor.inc.h>
{"type": "ignore"}
]
