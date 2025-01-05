#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Content
{
protected:
    string title;
    float rating;

public:
    Content(string title, float rating) : title(title), rating(rating)
    {
    }
    virtual void display() const
    {
        cout << "Title: " << title << ", Rating: " << rating << endl;
    }

    virtual void rate(float newRating)
    {
        rating = newRating;
    }

    float getRating() const
    {
        return rating;
    }
};
class IMDb : public Content
{
public:
    IMDb(string title, float rating) : Content(title, rating) {}

    void display() const override
    {
        cout << "IMDb Movie - ";
        Content::display();
    }
};
int main()
{
    IMDb movie("Inception", 8.8);
    movie.display();

    movie.rate(9.0);
    cout << "Updated ";
    movie.display();

    return 0;
}