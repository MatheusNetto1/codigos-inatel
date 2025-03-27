use std::io;

fn preenche_arr(arr: &mut [i32], x: i32) {
    for i in 0..arr.len() {
        arr[i] = i as i32 * x;
    }
}

pub fn main() {
    let mut arr = [0; 10];
    let mut number = String::new();

    io::stdin().read_line(&mut number).expect("Failed to read line");

    let number_cvt: i32 = number.trim().parse().expect("Failed to read line");

    preenche_arr(&mut arr, number_cvt);

    println!("{:?}", arr);
}