function expandedForm(num) {
	return num
		.toString()
		.split('')
		.map((d, i, a) => d * Math.pow(10, a.length - (i + 1)))
		.filter(a => a > 0)
		.join(' + ')
}

/*
function expandedForm(num) {
	return num
		.toString()
		.split('')
		.map((d, i, a) => (d === '0') ? '0' : d.concat('0'.repeat(a.length - (i + 1))))
		.join(' + ')
		.replace(/\s\+\s0/g, '');
}
*/
