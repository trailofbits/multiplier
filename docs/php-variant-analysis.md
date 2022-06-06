# PHP Variant Analysis Example

Using Multiplier to identify bugs similar to the vulnerability identified in
[pwning.systems](https://pwning.systems/posts/php_filter_var_shenanigans/).

## Clone and generate `compile_commands.json`

Clone PHP source and checkout the vulnerable commit:

```
$ git clone git@github.com:php/php-src.git
$ cd php-src
$ git checkout 414d5620
```

The vulnerable implicit cast can be confirmed in
`ext/filter/logical_filters.c`:

```c
...
507: static int _php_filter_validate_domain(char * domain, int len, zend_long flags) /* {{{ */
...
561: if (!_php_filter_validate_domain(Z_STRVAL_P(value), Z_STRLEN_P(value), flags)) {
...
```

Note that `_php_filter_validate_domain()` takes a second argument of type
`int`, but that on line 561, it is passed a `size_t` (from `Z_STRLEN_P()`).

Install deps (Ubuntu 20.04) and generate `compile_commands.json`:

```
$ sudo apt install -y pkg-config build-essential autoconf bison re2c \
                    libxml2-dev libsqlite3-dev
$ ./buildconf
$ ./configure
$ bear make -j `cat /proc/cpuinfo | grep processor | wc -l`
```

## Identify implicit cast vulnerability

Modify `compile_commands.json` to only contain entry for the compilation unit
for the `ext/filter/logical_filters.c` file (e.g. remove lines 2-1878,
1915-2847).

Start Multiplier indexer in one terminal:

```
$ ./bin/Index/mx-index --workspace_dir /tmp/ws/ --logtostderr --minloglevel 0
```

(All following commands should be executed in a separate terminal.)

Import the `compile_commands.json` file:

```
$ ./bin/Import/mx-import --path <path_to>/php-src/compile_commands.json
```

Identify the ID for the `ext/filter/logical_filters.c` file (note that ID
values will differ in different workspaces):

```
$ ./bin/Examples/mx-list-files
208	/home/huckfinn/tob/targets/php-src/TSRM/TSRM.h
260	/home/huckfinn/tob/targets/php-src/Zend/zend.h
90	/home/huckfinn/tob/targets/php-src/Zend/zend_API.h
156	/home/huckfinn/tob/targets/php-src/Zend/zend_alloc.h
155	/home/huckfinn/tob/targets/php-src/Zend/zend_alloc_sizes.h
<snip>
265	/home/huckfinn/tob/targets/php-src/ext/filter/logical_filters.c
<snip>
```

Identify the fragment ID of the functions of interest:

```
$ ./bin/Examples/mx-list-functions -file_id 265
265	65536	495	def	php_filter_validate_mac
265	65537	268435951	def	php_filter_validate_ip
265	65538	536871407	def	_php_filter_validate_ipv6
265	65539	805306863	def	_php_filter_validate_ipv4
265	65540	1073742319	def	php_filter_validate_email
265	65541	1342177775	def	php_filter_validate_url
265	65542	1610613231	def	is_userinfo_valid
265	65543	1879048687	def	php_filter_validate_domain
265	65544	2147484143	def	_php_filter_validate_domain
265	65545	2415919599	def	php_filter_validate_regexp
265	65546	2684355055	def	php_filter_float
265	65546	2684477559	decl	__builtin_constant_p
265	65546	2684481655	decl	__builtin_isfinite
265	65547	2952790511	def	php_filter_boolean
265	65548	3221225967	def	php_filter_int
265	65549	3489661423	def	php_filter_parse_hex
265	65550	3758096879	def	php_filter_parse_octal
265	65551	4026532335	def	php_filter_parse_int
265	65552	4294967415	decl	_php_filter_validate_ipv6
```

Find sketchy casts in the `php_filter_validate_domain()` function:

```
$ ./bin/Examples/mx-find-sketchy-casts -fragment_id 65543
( ( * ( value ) ) . value . str ) -> len
U_LONG -> INT
```

(Recognize that this what the expression looks like after macro expansions have
been applied. Can confirm this by printing the tokens in the fragment, and
notice that the first and second arguments to `_php_filter_validate_domain()`
have been expanded.)

```
$ ./bin/Examples/mx-print-fragment -fragment_id 65543
 void php_filter_validate_domain (  zval * value , zend_long flags , zval * option_array , char * charset  ) { if ( ! _php_filter_validate_domain (  ( ( * ( value ) ) . value . str ) -> val  ,  ( ( * ( value ) ) . value . str ) -> len  , flags ) ) {  if ( ( executor_globals . exception ) ) { return ; } else if ( flags & 0x8000000 ) { zval_ptr_dtor ( value ) ; do { ( * ( value ) ) . u1 . type_info = 1 ; } while ( 0 ) ; } else { zval_ptr_dtor ( value ) ; do { ( * ( value ) ) . u1 . type_info = 2 ; } while ( 0 ) ; } return ;  } }⏎
```

(Note: can also show the more readable unparsed tokens with the `-unparsed`
flag to `mx-print-fragment`.)

Get the entity ID of the `php_filter_validate_domain()` function:

```
$ ./bin/Examples/mx-list-functions -fragment_id 65543
265	65543	1879048687	def	php_filter_validate_domain
```

Get the call hierarchy of the `php_filter_validate_domain()` function using its
entity ID as reference:
```
$ ./bin/Examples/mx-print-call-hierarchy -entity_id 1879048687
php_filter_validate_domain	265             65543           1879048687      FUNCTION
```

This isn't helpful, because the only file indexed so far has been the
compilation unit for `ext/filter/logical_filters.c`. Index the rest of the PHP
source to make this useful (e.g. use the `mx-import` command as above, but
provide it with the entire unmodified `compile_commands.json` file generated by
`bear`).

## Identify implicit casts that also use the zstr->len field

The vulnerable implicit cast identified in [pwning.systems]
(https://pwning.systems/posts/php_filter_var_shenanigans/) is in the function
`php_filter_validate_domain()`. It passes the unsigned long parameter
`Z_STRLEN_P(value)` to the function `_php_filter_validate_domain()`, which
takes an `int` parameter. `Z_STRLEN_P` is actually, after some macro
expansions, a derefence of a `size_t len` field of an object of type
`_zend_string`, defined in `Zend/zend_string.h`. So to summarize,
the value of `Z_STRLEN_P(value)` is the `_zend_string.len` field.

We can use `mx-find-sketchy-casts` to identify all references to the
`_zend_string.len` field that are used as arguments to call expressions with
implicit casts, and possibly more instances of the vulnerability.

(Ensure that all of PHP is indexed before this example.)

To get the entity ID of the `_zend_string.len` field, first find the file ID
where it is defined, and then the entity ID of the field:

```
$ ./bin/Examples/mx-list-files | grep zend_types
228	/home/huckfinn/tob/targets/php-src/Zend/zend_types.h

$ ./bin/Examples/mx-list-structures -file_id 228 | grep -A 5 _zend_string
228	68540	806380110467	_zend_string
	806380114399	gc
	806380118495	h
	806380122591	len
	806380126687	val
```

(The entity ID of `len` is the 806380122591 value in the `len` row.)

Identify other possible instances of the vulnerable code pattern with this
entity:

```
$ ./bin/Examples/mx-find-sketchy-casts -entity_id 806380122591 -show_locations
/home/huckfinn/tob/targets/php-src/Zend/zend_language_scanner.c
file ID: 1145	frag ID: 7	U_LONG -> INT	( copy ) -> len

/home/huckfinn/tob/targets/php-src/ext/pdo_sqlite/sqlite_driver.c:425:20
file ID: 353	frag ID: 71077	U_LONG -> INT	( ( retval ) . value . str ) -> len

/home/huckfinn/tob/targets/php-src/ext/pdo_sqlite/sqlite_driver.c:231:4
file ID: 353	frag ID: 71090	U_LONG -> INT	2 *  ( unquoted ) -> len  + 3

/home/huckfinn/tob/targets/php-src/ext/pdo_sqlite/sqlite_driver.c:193:8
file ID: 353	frag ID: 71099	U_LONG -> INT	( sql ) -> len

/home/huckfinn/tob/targets/php-src/ext/pdo_sqlite/sqlite_statement.c:160:41
file ID: 493	frag ID: 75101	U_LONG -> INT	( ( * ( parameter ) ) . value . str ) -> len

/home/huckfinn/tob/targets/php-src/ext/pdo_sqlite/sqlite_statement.c:183:45
file ID: 493	frag ID: 75101	U_LONG -> INT	( ( * ( parameter ) ) . value . str ) -> len

/home/huckfinn/tob/targets/php-src/ext/filter/logical_filters.c:561:9
file ID: 583	frag ID: 79319	U_LONG -> INT	( ( * ( value ) ) . value . str ) -> len

/home/huckfinn/tob/targets/php-src/ext/dom/node.c:192:12
file ID: 648	frag ID: 82398	U_LONG -> INT	( str ) -> len  + 1

/home/huckfinn/tob/targets/php-src/ext/dom/attr.c:154:4
file ID: 987	frag ID: 92287	U_LONG -> INT	( str ) -> len  + 1

/home/huckfinn/tob/targets/php-src/ext/sqlite3/sqlite3.c:1845:14
file ID: 1001	frag ID: 92511	U_LONG -> INT	( sql ) -> len

/home/huckfinn/tob/targets/php-src/ext/sqlite3/sqlite3.c:1549:38
file ID: 1001	frag ID: 92518	U_LONG -> INT	( buffer ) -> len

/home/huckfinn/tob/targets/php-src/ext/sqlite3/sqlite3.c:1568:34
file ID: 1001	frag ID: 92518	U_LONG -> INT	( str ) -> len

/home/huckfinn/tob/targets/php-src/ext/sqlite3/sqlite3.c:840:20
file ID: 1001	frag ID: 92544	U_LONG -> INT	( str ) -> len

/home/huckfinn/tob/targets/php-src/ext/sqlite3/sqlite3.c:685:18
file ID: 1001	frag ID: 92545	U_LONG -> INT	( sql ) -> len

/home/huckfinn/tob/targets/php-src/ext/sqlite3/sqlite3.c:576:18
file ID: 1001	frag ID: 92547	U_LONG -> INT	( sql ) -> len

/home/huckfinn/tob/targets/php-src/ext/sqlite3/sqlite3.c:522:14
file ID: 1001	frag ID: 92548	U_LONG -> INT	( sql ) -> len

/home/huckfinn/tob/targets/php-src/ext/dom/processinginstruction.c:131:4
file ID: 1066	frag ID: 95143	U_LONG -> INT	( str ) -> len  + 1

/home/huckfinn/tob/targets/php-src/ext/dom/characterdata.c:73:4
file ID: 1151	frag ID: 98522	U_LONG -> INT	( str ) -> len  + 1
```

Current work: triage these instances to determine if any may be
vulnerabilities.

## Identifying calls to `sqlite_handle_quoter()`

mx-find-sketchy-casts identified an implicit cast of the argument to
`sqlite3_snprintf()` in the function `sqlite_handle_quoter()` in
`ext/pdo_sqlite/sqlite_driver.c`.

To identify where `sqlite_handle_quoter()` gets called:

```
$ ./bin/Examples/mx-list-files | grep sqlite_driver.c
746	/home/huckfinn/tob/targets/php-src/ext/pdo_sqlite/sqlite_driver.c

$ ./bin/Examples/mx-list-functions -file_id 746 | grep sqlite_handle_quoter
746	81935	4402073043439	sqlite_handle_quoter	def

$ ./bin/Examples/mx-print-call-hierarchy -entity_id 4402073043439
sqlite_handle_quoter	746	81935	4402073043439	FUNCTION	/home/huckfinn/tob/targets/php-src/ext/pdo_sqlite/sqlite_driver.c	227	21
  sqlite_methods	746	81917	4397241205475	VAR	/home/huckfinn/tob/targets/php-src/ext/pdo_sqlite/sqlite_driver.c	720	37
    pdo_sqlite_handle_factory	746	81914	4396435898863	FUNCTION	/home/huckfinn/tob/targets/php-src/ext/pdo_sqlite/sqlite_driver.c	792	12
      pdo_sqlite_driver	746	77087	3100697952995	VAR	/home/huckfinn/tob/targets/php-src/ext/pdo_sqlite/sqlite_driver.c	852	20
        zm_shutdown_pdo_sqlite	904	87473	5888668598767	FUNCTION	/home/huckfinn/tob/targets/php-src/ext/pdo_sqlite/pdo_sqlite.c
          pdo_sqlite_module_entry	904	87475	5889205469923	VAR	/home/huckfinn/tob/targets/php-src/ext/pdo_sqlite/pdo_sqlite.c	38	19
<snip>

$ ./bin/Examples/mx-list-uses -entity_id 4402073043439 -show_locations -highlight_user
<snip>
746	81917	4397241238871	DECL_REF_EXPR	/home/huckfinn/tob/targets/php-src/ext/pdo_sqlite/sqlite_driver.c	724	4
			DECLARATION
			FOUND_DECLARATION
			REFERENCED_DECLARATION_OF_CALLEE

	         +---------------------------------------------
	     720 | static const struct pdo_dbh_methods sqlite_methods = {
	     721 | 	sqlite_handle_closer,
	     722 | 	sqlite_handle_preparer,
	     723 | 	sqlite_handle_doer,
	     724 | 	sqlite_handle_quoter,
	     725 | 	sqlite_handle_begin,
	     726 | 	sqlite_handle_commit,
	     727 | 	sqlite_handle_rollback,
	     728 | 	pdo_sqlite_set_attr,
	     729 | 	pdo_sqlite_last_insert_id,
	     730 | 	pdo_sqlite_fetch_error_func,
	     731 | 	pdo_sqlite_get_attribute,
	     732 | 	NULL,	/* check_liveness: not needed */
	     733 | 	get_driver_methods,
	     734 | 	pdo_sqlite_request_shutdown,
	     735 | 	NULL, /* in transaction, use PDO's internal tracking mechanism */
	     736 | 	pdo_sqlite_get_gc
	     737 | }
<snip>
```

This shows that the `sqlite_handle_quoter` is registered as a function pointer
in the `sqlite_methods` struct, which is of type `pdo_dbh_methods`. To
determine where the uses of the `sqlite_handle_quoter` function pointer are, we
look up the field entity id of the `pdo_dbh_methods` struct, which is defined
in `php_pdo_driver.h`:

```
$ ./bin/Examples/mx-list-files | grep php_pdo_driver.h
384	/home/huckfinn/tob/targets/php-src/ext/pdo/php_pdo_driver.h

$ ./bin/Examples/mx-list-structures -file_id 384 | grep pdo_dbh_methods -A10
384	71938	1718523789955	pdo_dbh_methods
		1718523793887	closer
		1718523797983	preparer
		1718523802079	doer
		1718523806175	quoter
		1718523810271	begin
		1718523814367	commit
		1718523818463	rollback
		1718523822559	set_attribute
		1718523826655	last_id
		1718523830751	fetch_err

$ ./bin/Examples/mx-list-uses -entity_id 1718523806175 -show_locations -highlight_user
<snip>

$ ./bin/Examples/mx-list-uses -entity_id 1718523806175 -show_locations
384	71938	1718523806175	FIELD	/home/huckfinn/tob/targets/php-src/ext/pdo/php_pdo_driver.h	296	28
			UNDERLYING_DECLARATION
735	75649	2714692465975	IMPLICIT_CAST_EXPR	/home/huckfinn/tob/targets/php-src/ext/pdo/pdo_sql_parser.c	530	16
			REFERENCED_DECLARATION_OF_CALLEE
735	75649	2714692470195	MEMBER_EXPR	/home/huckfinn/tob/targets/php-src/ext/pdo/pdo_sql_parser.c	530	16
			MEMBER_DECLARATION
			REFERENCED_DECLARATION_OF_CALLEE
735	75649	2714692957439	CALL_EXPR	/home/huckfinn/tob/targets/php-src/ext/pdo/pdo_sql_parser.c	549	38
			CALLEE_DECLARATION
735	75649	2714692961591	IMPLICIT_CAST_EXPR	/home/huckfinn/tob/targets/php-src/ext/pdo/pdo_sql_parser.c	549	38
			REFERENCED_DECLARATION_OF_CALLEE
735	75649	2714692965811	MEMBER_EXPR	/home/huckfinn/tob/targets/php-src/ext/pdo/pdo_sql_parser.c	549	38
			MEMBER_DECLARATION
			REFERENCED_DECLARATION_OF_CALLEE
735	75649	2714693670143	CALL_EXPR	/home/huckfinn/tob/targets/php-src/ext/pdo/pdo_sql_parser.c	591	42
			CALLEE_DECLARATION
735	75649	2714693674295	IMPLICIT_CAST_EXPR	/home/huckfinn/tob/targets/php-src/ext/pdo/pdo_sql_parser.c	591	42
			REFERENCED_DECLARATION_OF_CALLEE
735	75649	2714693678515	MEMBER_EXPR	/home/huckfinn/tob/targets/php-src/ext/pdo/pdo_sql_parser.c	591	42
			MEMBER_DECLARATION
			REFERENCED_DECLARATION_OF_CALLEE
989	89620	6464999937279	CALL_EXPR	/home/huckfinn/tob/targets/php-src/ext/pdo/pdo_dbh.c
			CALLEE_DECLARATION
989	89620	6464999941431	IMPLICIT_CAST_EXPR	/home/huckfinn/tob/targets/php-src/ext/pdo/pdo_dbh.c
			REFERENCED_DECLARATION_OF_CALLEE
989	89620	6464999945651	MEMBER_EXPR	/home/huckfinn/tob/targets/php-src/ext/pdo/pdo_dbh.c
			MEMBER_DECLARATION
			REFERENCED_DECLARATION_OF_CALLEE
989	89620	6465003713847	IMPLICIT_CAST_EXPR	/home/huckfinn/tob/targets/php-src/ext/pdo/pdo_dbh.c	1176	9
			REFERENCED_DECLARATION_OF_CALLEE
989	89620	6465003718067	MEMBER_EXPR	/home/huckfinn/tob/targets/php-src/ext/pdo/pdo_dbh.c	1176	9
			MEMBER_DECLARATION
			REFERENCED_DECLARATION_OF_CALLEE
```
