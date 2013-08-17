#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#include "php.h"
#include "php_camel_case.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

zend_function_entry camel_case_functions[] = {
	PHP_FE(camel_case, NULL)
	PHP_FE(uncamel_case, NULL)
	{NULL, NULL, NULL}
};

zend_module_entry camel_case_module_entry = {
	STANDARD_MODULE_HEADER,
	PHP_CAMEL_CASE_EXTNAME,
	camel_case_functions,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	PHP_CAMEL_CASE_VERSION,
	STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_CAMEL_CASE
ZEND_GET_MODULE(camel_case)
#endif

PHP_FUNCTION(camel_case)
{
	char *str;
	char *sep="_";
	int str_len;
	int sep_len=1;
	int uc_next=1;
	zend_bool lc_first=0;
	int char_count = 0;
	char *source, *target, *source_end;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s|sb", &str, &str_len, &sep, &sep_len, &lc_first) == FAILURE) {
        RETURN_NULL();
    }

	if (!str_len) {
		RETURN_EMPTY_STRING();
	}

	if(lc_first) {
		uc_next = 0;
	}

	source_end=str+str_len;
	for (source = str; source < source_end; source++) {
		if (tolower(*source) == tolower(*sep)) {
			char_count++;
		}
	}

	Z_STRLEN_P(return_value) = str_len + (char_count * -1);
	Z_STRVAL_P(return_value) = target = safe_emalloc(char_count, 0, str_len+1);
	Z_TYPE_P(return_value) = IS_STRING;

	for (source = str; source < source_end; source++) {
		if (tolower(*source) == tolower(*sep)) {
			uc_next = 1;
		} else {
			if(uc_next) {
				*target = toupper(*source);
				uc_next = 0;
			} else {
				*target = tolower(*source);
			}

			target++;
		}
	}
}

PHP_FUNCTION(uncamel_case)
{
	char *str;
	char *sep="_";
	int str_len;
	int sep_len=1;
	int uc_next=1;
	int char_count = 0;
	char *source, *target, *source_end;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s|sb", &str, &str_len, &sep, &sep_len) == FAILURE) {
        RETURN_NULL();
    }

	if (!str_len) {
		RETURN_EMPTY_STRING();
	}

	source_end=str+str_len;
	for (source = str + 1; source < source_end; source++) {
		if (isupper(*source)) {
			char_count++;
		}
	}

	Z_STRLEN_P(return_value) = str_len + char_count;
	Z_STRVAL_P(return_value) = target = safe_emalloc(char_count, 1, str_len+1);
	Z_TYPE_P(return_value) = IS_STRING;

	*target = tolower(*str);
	target++;
	for (source = str + 1; source < source_end; source++) {
		if (isupper(*source)) {
			*target = tolower(*sep);
			target++;
		}

		*target = tolower(*source);
		target++;
	}
}
