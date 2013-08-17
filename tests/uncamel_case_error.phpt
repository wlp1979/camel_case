--TEST--
camel_case() function - error test for camel_case()
--FILE--
<?php
$input = array("camel_case_me");
var_dump(uncamel_case($input));
?>
--EXPECTF--
Warning: uncamel_case() expects parameter 1 to be string, array given %s
NULL