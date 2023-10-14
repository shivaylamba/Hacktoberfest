import java.io.File;
import java.util.Scanner;
import javax.sound.sampled.AudioInputStream;
import javax.sound.sampled.AudioSystem;
import javax.sound.sampled.Clip;
//Create new folder Songs and Add some songs in WAV format.
class MusicPlayer {


    static Scanner sc = new Scanner(System.in);
    class Songs {
        
        Songs next, prev;
        int number;
        String name, singerName, type;
        AudioInputStream audioStream;
        Clip clip;

        Songs(File f) throws Exception {
            this.next = null;
            this.prev = null;
            this.audioStream = AudioSystem.getAudioInputStream(f);
            this.clip = AudioSystem.getClip();
            clip.open(audioStream);
        }

        void play() {
            clip.setMicrosecondPosition(0);
            clip.start();
        }

        void pause() {
            clip.stop();
        }
    }

    Songs playlist = null;
    static File allSongs[];

    MusicPlayer() {
        File folder = new File("C:\\Users\\Harry Potter\\Desktop\\JAVA-II\\All Songs"); // Change location accordingly
        allSongs = folder.listFiles();
    }

    void displayAllSongs() { // done

        for (int i = 0; i < allSongs.length; i++) {
            System.out.println((i + 1) + " " + allSongs[i].getName().split(".wav")[0]);
        }
    }

    void displayPlaylistSongs() {//
        System.out.println("----------------Playlist songs--------------------");
        Songs temp = playlist;
        if (playlist == null) {
            System.out.println("Playlist Is Empty");
        } else {
            int i = 1;
            while (temp != null) {
                System.out.println((i) + "." + temp.name);
                temp = temp.next;
                i++;
            }
        }
        System.out.println("-----------------------------------------");

    }

    void addSong(int number) throws Exception {// done
        Songs newSong = new Songs(allSongs[number - 1]);
        newSong.name = allSongs[number - 1].getName();
        newSong.number = number - 1;
        if (playlist == null) {
            playlist = newSong;
        } else {
            Songs temp = playlist;
            while (temp.next != null) {
                temp = temp.next;
            }
            temp.next = newSong;
            newSong.prev = temp;
        }
        System.out.println("-----------------------------------------");
    }

    void removeSong(int number) throws Exception {// done
        Songs temp = playlist;
        System.out.println("--------------------------------------------------");
        if (playlist == null) {
            System.out.println("Playlist Is Empty");
        } else if (temp.name.equals(allSongs[number - 1].getName())) {
            playlist = playlist.next;
        } else {
            while (!temp.name.equals(allSongs[number - 1].getName())) {
                temp = temp.next;
            }
            temp.prev.next = temp.next;
        }
        System.out.println("-----------------------------------------");
    }

    void playAllSong() throws Exception {// done
        for (int i = 0; i < allSongs.length; i++) {
            playSingleSong(i);
        }
        
    }

    void playPlaylistSong() {
        Songs temp = playlist;
        if (playlist != null) {
            System.out.println("-------------------------------------------------- \nPlaying Song " + temp.name);
            String entry = "";
            temp.play();
            boolean isPaused = false;

            while (!entry.equalsIgnoreCase("Q")) {
                System.out.println(
                        "Enter 'P' to pause, 'R' to resume, 'N' for next song, 'B' for previous song, or 'Q' to stop.");
                entry = sc.nextLine();

                if (entry.equalsIgnoreCase("P")) {
                    if (!isPaused) {
                        temp.pause();
                        System.out.println("Paused. Press 'R' to resume.");
                        isPaused = true;
                    }
                } else if (entry.equalsIgnoreCase("R")) {
                    if (isPaused) {
                        temp.play();
                        System.out.println("Resumed. Press 'P' to pause.");
                        isPaused = false;
                    }
                } else if (entry.equalsIgnoreCase("N")) {
                    if (temp.next != null) {
                        temp.pause();
                        temp = temp.next;
                        temp.play();
                        System.out.println("Playing next song: " + temp.name);
                    } else {
                        System.out.println("No more songs in the playlist.");
                    }
                } else if (entry.equalsIgnoreCase("B")) {
                    if (temp.prev != null) {
                        temp.pause();
                        temp = temp.prev;
                        temp.play();
                        System.out.println("Playing previous song: " + temp.name);
                    } else {
                        System.out.println("No previous songs in the playlist.");
                    }
                } else if (!entry.equalsIgnoreCase("Q")) {
                    System.out.println("Invalid input. Please enter a valid command.");
                }
            }

            // Stop the song when the loop exits (user enters "Quit")
            temp.pause();
        } else {
            System.out.println("Can't Play A Song Because Playlist Is Empty");
        }
    }

    void playSingleSong(int number) throws Exception {
        Songs temp = new Songs(allSongs[number]);
        temp.play();
        System.out.println("-------------------------------------------------- \nPlaying Song");
        String entry = "";

        while (!entry.equalsIgnoreCase("Q")) {
            System.out.println("Enter 'P' to pause, 'R' to resume, or 'Q' to stop.");
            entry = sc.nextLine();

            if (entry.equalsIgnoreCase("P")) {
                temp.pause();
                System.out.println("Paused. Press 'R' to resume.");
            } else if (entry.equalsIgnoreCase("R")) {
                temp.play();
                System.out.println("Resumed. Press 'P' to pause.");
            } else if (!entry.equalsIgnoreCase("Q")) {
                System.out.println("Invalid input. Please enter a valid command.");
            }
        }

        temp.pause();
    }

    int getSizeOfLinkList() {
        Songs temp = playlist;
        int count = 0;
        while (temp != null) {
            temp = temp.next;
            count++;
        }
        return count;
    }

    boolean arrayContainsElement(int a[], int num) {
        for (int i = 0; i < a.length; i++) {
            if (a[i] == num)
                return false;
        }
        return true;
    }

    void shufflePlaylist() {
        if (playlist == null || getSizeOfLinkList() < 2) {
            System.out.println("Not enough songs in the playlist to shuffle.");
            return;
        }

        Songs[] playlistArray = new Songs[getSizeOfLinkList()];
        int index = 0;
        Songs temp = playlist;
        while (temp != null) {
            playlistArray[index] = temp;
            temp = temp.next;
            index++;
        }

        for (int i = playlistArray.length - 1; i > 0; i--) {
            int j = (int) (Math.random() * (i + 1));
            Songs tempSong = playlistArray[i];
            playlistArray[i] = playlistArray[j];
            playlistArray[j] = tempSong;
        }

        playlist = playlistArray[0];
        playlist.prev = null;
        temp = playlist;
        for (int i = 1; i < playlistArray.length; i++) {
            temp.next = playlistArray[i];
            playlistArray[i].prev = temp;
            temp = temp.next;
        }
        temp.next = null;

        System.out.println("Playlist shuffled successfully.");
        displayPlaylistSongs();
    }

    public static void main(String[] args) throws Exception {
        int choice;
        MusicPlayer m = new MusicPlayer();
        Scanner sc = new Scanner(System.in);

        do {
            System.out.println("--------------------------------------");

            System.out.println("Welcome To MyMusicPlayer");
            System.out.println("1. Add Song To Playlist");
            System.out.println("2. Remove Song From Playlist");
            System.out.println("3. Display Available Songs");
            System.out.println("4. Display Songs In Playlist");
            System.out.println("5. Play All Songs ");
            System.out.println("6. Play Songs in Playlist ");
            System.out.println("7. Play Single Song");
            System.out.println("8. Shuffle Playlist");
            System.out.println("9. Exit");

            System.out.print("Choose from (1-9) ");
            choice = sc.nextInt();

            switch (choice) {
                case 1: {
                    m.displayAllSongs();
                    System.out.print("\nEnter Song Number Which You Want To Add: ");
                    int number = sc.nextInt();
                    m.addSong(number);
                    System.out.println(allSongs[number - 1] + " Song Added");
                    System.out.println("-----------------------------------------");

                    System.out.println("");
                }
                    break;

                case 2: {
                    m.displayPlaylistSongs();
                    System.out.print("Enter Song Number Which You Want To Remove: ");
                    int number = sc.nextInt();
                    m.removeSong(number);
                    System.out.println(allSongs[number - 1] + " Song Removed");
                    System.out.println("--------------------------------------");
                }
                    break;

                case 3: {
                    m.displayAllSongs();
                }
                    break;

                case 4: {
                    m.displayPlaylistSongs();
                }
                    break;

                case 5: {
                    m.playAllSong();
                }
                    break;

                case 6: {
                    m.playPlaylistSong();
                }
                    break;

                case 7: {
                    System.out.println("--------------------------------------------------");
                    m.displayAllSongs();
                    System.out.println("--------------------------------------------------");
                    System.out.print("Enter Song Number Which You Want To Play: ");
                    int number = sc.nextInt()-1;
                    m.playSingleSong(number);
                }
                    break;

                case 8: {
                    m.shufflePlaylist();
                }
                    break;

                case 9: {
                    sc.close();
                    System.exit(0);
                }
                    break;

                default:
                    System.out.println("Enter Valid Choice");
            }
        } while (choice != 9);
    }
}