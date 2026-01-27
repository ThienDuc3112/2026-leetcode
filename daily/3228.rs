impl Solution {
    pub fn max_operations(s: String) -> i32 {
        let mut ans = 0;
        let mut count = 0;
        let mut last_char = false;
        for c in s.chars() {
            if c == '1' {
                last_char = true;
                count += 1;
            } else if last_char {
                last_char = false;
                ans += count;
            }
        }
        ans
    }
}
