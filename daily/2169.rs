impl Solution {
    pub fn count_operations(num1: i32, num2: i32) -> i32 {
        if num1 == 0 || num2 == 0 {
            return 0;
        }

        let (max, min) = if num1 > num2 {
            (num1, num2)
        } else {
            (num2, num1)
        };

        return max / min + Self::count_operations(min, max % min);
    }
}
