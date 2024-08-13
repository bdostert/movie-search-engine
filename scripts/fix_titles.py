#max title length = 181

import os
import re

# ensure to delete final character in string if it is colon

def main():
    if not os.path.isfile("../data/MovieTitles.txt"):
        print("data file does not exist. Run scraper.py.")
        return;

    file = open('../data/MovieTitles.txt', 'r')
    fixed_titles = []

    for line in file:
        line_length = len(line)
        if line_length < 5:
            continue

        start_year_info = line.rfind('(')
        #rfind returns -1 if bad. index 2 is earliest possible for year info
        if start_year_info < 2:
            continue
         
        title = line[0: start_year_info - 2 if line[start_year_info - 2] == ':'
                                            else start_year_info - 1] 
        #find all years in year_info substring 
        years = re.findall(r'\d{4}', line[start_year_info : line_length])
        for year in years:
            fixed_titles.append(title + " (" + year + ")")

    file = open('../data/MovieTitles.txt', 'w')
    for title in fixed_titles:
        file.write(title + '\n') 

if __name__ == '__main__':
    main()
