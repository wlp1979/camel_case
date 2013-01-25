PHP_ARG_ENABLE(camel_case, whether to enable CamelCase support,[ --enable-camel-case	Enable CamelCase support])

if test "$PHP_CAMEL_CASE" = "yes"; then
	AC_DEFINE(HAVE_CAMEL_CASE, 1, [Whether you have CamelCase])
	PHP_NEW_EXTENSION(camel_case, camel_case.c, $ext_shared)
fi
