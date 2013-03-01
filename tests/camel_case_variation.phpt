--TEST--
camel_case() function - variation test for camel_case()
--FILE--
<?php
$input = "camel-case-me";
var_dump(camel_case($input, "-"));
?>
--EXPECT--
string(11) "CamelCaseMe"
