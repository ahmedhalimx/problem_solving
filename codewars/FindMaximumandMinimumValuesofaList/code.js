var min = function(list) {
	let min = list[0];
	list.sort((a) => min = (a < min) ? a : min);
	return min;
}

var max = function(list) {
	let max = list[0];
	list.sort((a) => max = (a > max) ? a : max);
	return max;
}

/* Better Solution
	var min = function(list) {
		return Math.min(...list);
	}
	
	var max = function(list) {
		return Math.max(...list);
	}
*/

const arar = [1, 5, null, 3, 7, 8, Infinity];
console.log(`Min: ${min(arar)}, Max: ${max(arar)}`);
