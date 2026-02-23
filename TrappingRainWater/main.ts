function trap(height: number[]): number {
	let TotalWaterCollectionCount = 0
	let currentWaterCollectionCount = 0
	let left = 0
	while (left < height.length) {
		currentWaterCollectionCount = 0
		for (let right = left + 1; right <= height.length; right++) {
			if (height[right] >= height[left]) {
				//add unit/units of water to count
				TotalWaterCollectionCount += currentWaterCollectionCount
				left = right
				break
			} else if (right == height.length) {
				left++
				break
			} else {
				currentWaterCollectionCount += height[left] - height[right]
			}
		}
	}
	return TotalWaterCollectionCount
};

if (trap([0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]) == 6) {
	console.log("success")
} else {
	console.log("fail")
}

if (trap([4, 2, 0, 3, 2, 5]) == 9) {
	console.log("success")
} else {
	console.log("fail")
}

if (trap([4, 2, 3]) == 1) {
	console.log("success")
} else {
	console.log("fail")
}
