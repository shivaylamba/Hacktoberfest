from pygame import mixer
mixer.init()
mixer.music.load("song.mp3") # Here replace song.mp3 with the name of the song you want to play and that song file should be in same folder
mixer.music.set_volume(0.3)
mixer.music.play()

while True:
    print("Press 'p' to pause and 'r' to resume")
    print("Press 'e' to exit the program")
    query=input(">>> ")
    if query == 'p':
        mixer.music.pause()
    elif query == 'r':
        mixer.music.unpause()
    elif query == 'e':
        mixer.music.stop()
        break
