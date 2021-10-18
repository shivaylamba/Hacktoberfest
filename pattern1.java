public class Library {

    int acc_num;
    String title;
    String author;

    public void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("Enter accession number: ");
        acc_num = Integer.parseInt(br.readLine());
        System.out.print("Enter title: ");
        title = br.readLine();
        System.out.print("Enter author: ");
        author = br.readLine();
    }

    public void compute() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("Enter number of days late: ");
        int daysLate = Integer.parseInt(br.readLine());;
        int fine = 2 * daysLate;
        System.out.println("Fine is Rs " + fine);
    }

    public void display() {
        System.out.println("Accession Number\tTitle\tAuthor");
        System.out.println(acc_num + "\t" + title + "\t" + author);
    }

    public static void main(String[] args) throws IOException {
        Library library = new Library();
        library.input();
        library.compute();
        library.display();
    }
}
