--TEST--
camel_case() function - variation test for camel_case()
--FILE--
<?php
$input = "camel_case_me";
var_dump(camel_case($input, "_", true));
?>
--EXPECT--
string(11) "camelCaseMe"
