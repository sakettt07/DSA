// This was my interview question from the DeltaX about the oops concept
// TO make aSpotify class ---->Music Apps (eg: iTunes, Spotify)
// App has a list of songs. Each song belongs to an album and is sung by a singer. Users can browse albums and their songs. Users can favorite albums.
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

// Song Class
class Song
{
    string name;
    string artist;

public:
    Song(string name, string artist) : name(name), artist(artist) {}

    string getName() const { return name; }
    string getArtist() const { return artist; }

    void display() const
    {
        cout << "Song: " << name << ", Artist: " << artist << endl;
    }
};

// Playlist Class
class Playlist
{
    string name;
    vector<Song> songs;

public:
    Playlist(string name) : name(name) {}

    void addSong(const Song &song)
    {
        songs.push_back(song);
    }

    void display() const
    {
        cout << "Playlist: " << name << endl;
        for (const auto &song : songs)
        {
            song.display();
        }
    }
};

// Spotify Class
class Spotify
{
    vector<Song> library;
    unordered_map<string, Playlist> playlists;
    vector<string> users;

public:
    // Add a song to the library
    void addSong(string name, string artist)
    {
        library.emplace_back(name, artist);
    }

    // Create a playlist
    void createPlaylist(string playlistName, vector<string> songNames)
    {
        Playlist newPlaylist(playlistName);

        for (const auto &songName : songNames)
        {
            bool found = false;
            for (const auto &song : library)
            {
                if (song.getName() == songName)
                {
                    newPlaylist.addSong(song);
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                throw invalid_argument("Song " + songName + " not found in library.");
            }
        }

        playlists[playlistName] = newPlaylist;
    }

    // Add a user
    void addUser(string userName)
    {
        users.push_back(userName);
    }

    // Add a song to an existing playlist
    void addSongToPlaylist(string playlistName, string songName)
    {
        if (playlists.find(playlistName) == playlists.end())
        {
            throw invalid_argument("Playlist " + playlistName + " does not exist.");
        }

        bool found = false;
        for (const auto &song : library)
        {
            if (song.getName() == songName)
            {
                playlists[playlistName].addSong(song);
                found = true;
                break;
            }
        }
        if (!found)
        {
            throw invalid_argument("Song " + songName + " not found in library.");
        }
    }

    // Play a song
    void playSong(string songName) const
    {
        for (const auto &song : library)
        {
            if (song.getName() == songName)
            {
                cout << "Playing: ";
                song.display();
                return;
            }
        }
        throw invalid_argument("Song " + songName + " not found in library.");
    }

    // Display all songs in the library
    void displayLibrary() const
    {
        cout << "Library:" << endl;
        for (const auto &song : library)
        {
            song.display();
        }
    }

    // Display all playlists
    void displayPlaylists() const {
    for (const auto& pair : playlists) {
        cout << "Playlist Name: " << pair.first << endl;
        pair.second.display(); 
        
    }
}
};

// Main Function
int main()
{
    Spotify spotify;

    try
    {
        // Add songs to the library
        spotify.addSong("Shape of You", "Ed Sheeran");
        spotify.addSong("Blinding Lights", "The Weeknd");
        spotify.addSong("Levitating", "Dua Lipa");

        // Add users
        spotify.addUser("Alice");
        spotify.addUser("Bob");

        // Create a playlist
        spotify.createPlaylist("My Favorites", {"Shape of You", "Blinding Lights"});

        // Add a song to an existing playlist
        spotify.addSongToPlaylist("My Favorites", "Levitating");

        // Play a song
        spotify.playSong("Shape of You");

        // Display library
        spotify.displayLibrary();

        // Display playlists
        spotify.displayPlaylists();
    }
    catch (const exception &e)
    {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
