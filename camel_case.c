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

static void strip_sep(char *str, uint len, char from, zval *result) {
	int char_count = 0;
	int replaced = 0;
	char *source, *target, *tmp, *source_end=str+len, *tmp_end = NULL;

	for (source = str; source < source_end; source++) {
		if (tolower(*source) == tolower(from)) {
			char_count++;
		}
	}

	Z_STRLEN_P(result) = len + (char_count * -1);
	Z_STRVAL_P(result) = target = safe_emalloc(char_count, 0, len + 1);
	Z_TYPE_P(result) = IS_STRING;

	for (source = str; source < source_end; source++) {
		if (tolower(*source) == tolower(from)) {
			replaced = 1;
			for (tmp = "", tmp_end = tmp; tmp < tmp_end; tmp++) {
				*target = *tmp;
				target++;
			}
		} else {
			*target = *source;
			target++;
		}
	}
	*target = 0;
}


PHP_FUNCTION(camel_case)
{
	char *str;
	char *sep="_";
	register char *r, *r_end;
	int str_len;
	int sep_len=1;
	zend_bool lc_first=0;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s|sb", &str, &str_len, &sep, &sep_len, &lc_first) == FAILURE) {
        RETURN_NULL();
    }

	if (!str_len) {
		RETURN_EMPTY_STRING();
	}

	ZVAL_STRINGL(return_value, str, str_len, 1);
	r = Z_STRVAL_P(return_value);

	if(lc_first) {
		*r = tolower((unsigned char) *r);
	}
	else {
		*r = toupper((unsigned char) *r);
	}
	r++;
	for (r_end = r + str_len - 1; r < r_end; ) {
		if ((unsigned char) *r == *sep ) {
			r++;
			*r = toupper((unsigned char) *r);
			r++;
		}
		else {
			*r = tolower((unsigned char) *r);
			r++;
		}
	}

	strip_sep(Z_STRVAL_P(return_value), Z_STRLEN_P(return_value), *sep, return_value);
}
