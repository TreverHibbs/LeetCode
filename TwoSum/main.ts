function twoSum(nums: number[], target: number): number[] {
	for (let i = 0; i < nums.length; i++) {
		for (let j = 0; j < nums.length; j++) {
			if (j == i) {
				break
			} else if (nums[i] + nums[j] == target) {
				return [i, j]
			}
		}
	}
	return nums
};

let testArray = [2, 7, 11, 15]
let returnArray = twoSum(testArray, 9)
if (testArray[returnArray[0]] + testArray[returnArray[1]] != 9) {
	console.log("fail")
} else {
	console.log("success")
}

testArray = [3, 2, 4]
returnArray = twoSum(testArray, 6)
if (testArray[returnArray[0]] + testArray[returnArray[1]] != 6) {
	console.log("fail")
} else {
	console.log("success")
}

testArray = [3, 3]
returnArray = twoSum(testArray, 6)
if (testArray[returnArray[0]] + testArray[returnArray[1]] != 6) {
	console.log("fail")
} else {
	console.log("success")
}

