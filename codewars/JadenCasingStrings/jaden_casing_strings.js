String.prototype.toJadenCase = function() {
	return this.replace(/(^|\s)[a-z]/g, function(x) {
		return x.toUpperCase();
	});
};

let Mname = "jadin will smith";
let r = String.prototype.toJadenCase(Mname);

console.log(r);
