function searchMatrix(matrix: number[][], target: number): boolean {
	let totalEntriesInMatrix = matrix[0].length * matrix.length
	function numberToCoord(num: number): number[] {
		let y = Math.floor(num / matrix[0].length)
		let x = num % matrix[0].length
		return [x, y]
	}

	//we will index the matrix like this
	//  0 1 2
	//0 # # #
	//1 # # #
	//2 # # #
	//The index of the row will be the first element of the coordinate
	//and the index of the column will be the second.
	//inclusive
	let left = 0
	//inclusive
	let right = totalEntriesInMatrix - 1

	while (left <= right) {
		let mid = Math.floor((right - left) / 2) + left
		let midCoord = numberToCoord(mid)

		if (matrix[midCoord[1]][midCoord[0]] == target) {
			return true
		} else if (matrix[midCoord[1]][midCoord[0]] > target) {
			right = mid - 1
		} else {
			left = mid + 1
		}
	}

	return false
}

if (searchMatrix([[1, 3, 5, 7], [10, 11, 16, 20], [23, 30, 34, 60]], 3) == true) {
	console.log("success")
} else {
	console.log("fail")
}

if (searchMatrix([[1, 3, 5, 7], [10, 11, 16, 20], [23, 30, 34, 60]], 13) == false) {
	console.log("success")
} else {
	console.log("fail")
}
