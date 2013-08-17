#ifndef PHP_CAMEL_CASE_H
#define PHP_CAMEL_CASE_H 1
#define PHP_CAMEL_CASE_VERSION "1.0"
#define PHP_CAMEL_CASE_EXTNAME "camel_case"

PHP_FUNCTION(camel_case);
PHP_FUNCTION(uncamel_case);

extern zend_module_entry camel_case_module_entry;
#define phpext_camel_case_ptr &camel_case_module_entry

#endif