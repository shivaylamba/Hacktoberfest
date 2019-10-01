
use rand::Rng;
use std::io;
fn main() {
    welcome_screen();

    let secret = rand::thread_rng().gen_range(1, 101);
    println!("The secret number is {}", secret);

    println!("Please enter a number!");

    let mut guess = String::new();

    io::stdin()
        .read_line(&mut guess)
        .expect("Failed to get input");

}


fn welcome_screen() {
    println!("GUESSING GAME!");
}