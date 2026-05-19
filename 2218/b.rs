use std::io::{Read, stdin};

fn solve(scan: &mut std::str::SplitWhitespace) {
    macro_rules! next {
        () => {
            scan.next().unwrap()
        };
        ($t:ty) => {
            scan.next().unwrap().parse::<$t>().unwrap()
        };
    }
    let mut a = vec![0; 7];
    for i in 0..7 {
        a[i] = next!(i32);
    }
    a.sort_unstable();
    let mut ans = 0;
    for i in 0..6 {
        ans -= a[i];
    }
    ans += a[6];
    println!("{}", ans);
}

fn main() {
    let mut input = String::new();
    stdin().read_to_string(&mut input).unwrap();
    let mut scan = input.split_whitespace();
    let t = scan.next().unwrap().parse::<usize>().unwrap();
    for _ in 0..t {
        solve(&mut scan);
    }
    // solve(&mut scan);
}
