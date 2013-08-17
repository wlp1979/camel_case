--TEST--
camel_case() function - basic test for camel_case()
--FILE--
<?php
$input = "CamelCaseMe";
var_dump(uncamel_case($input, '-'));
?>
--EXPECT--
string(13) "camel-case-me"
