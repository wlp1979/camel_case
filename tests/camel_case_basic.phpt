--TEST--
camel_case() function - basic test for camel_case()
--FILE--
<?php
$input = "camel_case_me";
var_dump(camel_case($input));
?>
--EXPECT--
string(11) "CamelCaseMe"
