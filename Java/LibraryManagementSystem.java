import java.util.*;

class Book {
    private String title;
    private String author;
    private String isbn;

    public Book(String title, String author, String isbn) {
        this.title = title;
        this.author = author;
        this.isbn = isbn;
    }

    public String getTitle() { return title; }
    public String getAuthor() { return author; }
    public String getIsbn() { return isbn; }

    @Override
    public String toString() {
        return "📘 " + title + " by " + author + " [ISBN: " + isbn + "]";
    }
}

public class LibraryManagementSystem {
    private static ArrayList<Book> library = new ArrayList<>();
    private static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int choice;
        do {
            System.out.println("\n===== 📚 LIBRARY MANAGEMENT SYSTEM =====");
            System.out.println("1. Add Book");
            System.out.println("2. View All Books");
            System.out.println("3. Search Book by Title");
            System.out.println("4. Remove Book by ISBN");
            System.out.println("5. Exit");
            System.out.print("Enter your choice: ");
            choice = sc.nextInt();
            sc.nextLine();

            switch (choice) {
                case 1 -> addBook();
                case 2 -> viewBooks();
                case 3 -> searchBook();
                case 4 -> removeBook();
                case 5 -> System.out.println("Exiting... Goodbye! 👋");
                default -> System.out.println("Invalid choice. Please try again.");
            }
        } while (choice != 5);
    }

    private static void addBook() {
        System.out.print("Enter Book Title: ");
        String title = sc.nextLine();
        System.out.print("Enter Author Name: ");
        String author = sc.nextLine();
        System.out.print("Enter ISBN: ");
        String isbn = sc.nextLine();

        Book book = new Book(title, author, isbn);
        library.add(book);
        System.out.println("✅ Book added successfully!");
    }

    private static void viewBooks() {
        if (library.isEmpty()) {
            System.out.println("📂 No books found in the library.");
        } else {
            System.out.println("\n📚 List of Books:");
            library.forEach(System.out::println);
        }
    }

    private static void searchBook() {
        System.out.print("Enter Title to search: ");
        String title = sc.nextLine();
        boolean found = false;
        for (Book b : library) {
            if (b.getTitle().equalsIgnoreCase(title)) {
                System.out.println("🔍 Found: " + b);
                found = true;
            }
        }
        if (!found) System.out.println("❌ No book found with title: " + title);
    }

    private static void removeBook() {
        System.out.print("Enter ISBN of the book to remove: ");
        String isbn = sc.nextLine();
        boolean removed = library.removeIf(b -> b.getIsbn().equals(isbn));
        if (removed)
            System.out.println("🗑️ Book removed successfully!");
        else
            System.out.println("❌ Book not found!");
    }
}