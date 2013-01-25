#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#include "php.h"
#include "php_camel_case.h"

static function_entry camel_case_functions[] = {
    PHP_FE(camel_case, NULL)
    {NULL, NULL, NULL}
};

zend_module_entry camel_case_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
    STANDARD_MODULE_HEADER,
#endif
    PHP_CAMEL_CASE_EXTNAME,
    camel_case_functions,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
#if ZEND_MODULE_API_NO >= 20010901
    PHP_CAMEL_CASE_VERSION,
#endif
    STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_CAMEL_CASE
ZEND_GET_MODULE(camel_case)
#endif

PHP_FUNCTION(camel_case)
{
    RETURN_STRING("Hello World", 1);
}