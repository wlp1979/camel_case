<?php
function toCamelCase($text, $separator = "_"){
    $parts = explode($separator, $text);
    
    foreach($parts as $key => $value)
    {
        $parts[$key] = ucfirst(strtolower($value));
    }
    
    return implode('', $parts);
}

function quickCamelCase($text, $separator = "_") {
	return str_replace(" ", "", ucwords(str_replace($separator, " ", $text)));
}

$functions = array(
	'toCamelCase',
	'quickCamelCase',
	'camel_case',
	);

$string = "some_column_name";
$loops = 100000;
foreach($functions as $function) {
	$start = microtime(TRUE);
	for($i=0; $i < $loops; $i++) {
		$function($string);
	}
	$end = microtime(true);
	$total = ($end - $start) * 1000;

	printf("%s: %.0f ms\n", $function, $total);
}
