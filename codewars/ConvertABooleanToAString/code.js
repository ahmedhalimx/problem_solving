function booleanToString(b) {
	return (b) ? "true" : "false";
}

function booleanToString2(b) {
	return b.toString();
}

console.log(typeof booleanToString2(true));
