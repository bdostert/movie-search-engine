'''
Simple web scraper to get all movie titles from the below wiki link
https://en.wikipedia.org/wiki/List_of_films:_A
'''
import requests 
import os
from bs4 import BeautifulSoup #for parsing HTML 


def main():
    if os.path.isfile("../data/MovieTitles.txt"):
        os.remove("../data/MovieTitles.txt");

    file = open('../data/MovieTitles.txt', 'a')
    
    subpages = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J-K', 'L', 'M',
                'N-O', 'P', 'Q-R', 'S', 'T', 'U-W', 'X-Z']

    for subpage in subpages:
        url = "https://en.wikipedia.org/wiki/List_of_films:_" + subpage
        response = requests.get(url)
        print(f"Scraping: {url}, {response}")
        
        soup = BeautifulSoup(response.content, 'html.parser')
        #print(soup.prettify)
        titles = soup.find_all(class_='div-col')

        for title in titles:
            movie_title = title.get_text();

            file.write(movie_title)

    file.close()
    


if __name__ == '__main__':
    main()
