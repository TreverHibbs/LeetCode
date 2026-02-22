function isValid(s: string): boolean {
	return false
};

if (isValid("()") == true) {
	console.log("success")
} else {
	console.log("fail")
}


if (isValid("()[]{}") == true) {
	console.log("success")
} else {
	console.log("fail")
}

if (isValid("(]") != true) {
	console.log("success")
} else {
	console.log("fail")
}

if (isValid("([])") == true) {
	console.log("success")
} else {
	console.log("fail")
}

if (isValid("([)]") != true) {
	console.log("success")
} else {
	console.log("fail")
}
