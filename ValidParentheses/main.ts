function isValid(s: string): boolean {
	let stack: string[] = []
	for (let i = 0; i < s.length; i++) {
		if (s[i] == ")") {
			let bracketToTest = stack.pop()
			if (bracketToTest != "(") {
				return false
			}
		} else if (s[i] == "]") {
			let bracketToTest = stack.pop()
			if (bracketToTest != "[") {
				return false
			}
		} else if (s[i] == "}") {
			let bracketToTest = stack.pop()
			if (bracketToTest != "{") {
				return false
			}
		} else {
			stack.push(s[i])
		}
	}
	if (stack.length == 0) {
		return true
	} else {
		return false
	}
}

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

if (isValid("[") != true) {
	console.log("success")
} else {
	console.log("fail")
}
