'''
Simple web scraper to get all movie titles from the below wiki link
https://en.wikipedia.org/wiki/List_of_films:_A
'''
import requests 
from bs4 import BeautifulSoup #for parsing HTML 


def main():
    
    subpages = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J-K', 'L', 'M',
                'N-O', 'P', 'Q-R', 'S', 'T', 'U-W', 'X-Z']

    for subpage in subpages:
        url = "https://en.wikipedia.org/wiki/List_of_films:_" + subpage
        response = requests.get(url)
        
        soup = BeautifulSoup(response.content, 'html.parser')
        titles = soup.find_all(class_='div-col')

        print(f"Scraping: {url}")
        print(response)
        #print(soup.prettify)
        print(titles)
        break



if __name__ == '__main__':
    main()
