import os
import random
import re
import sys

DAMPING = 0.85
SAMPLES = 10000


def main():
    if len(sys.argv) != 2:
        sys.exit("Usage: python pagerank.py corpus")
    corpus = crawl(sys.argv[1])
    ranks = sample_pagerank(corpus, DAMPING, SAMPLES)
    print(f"PageRank Results from Sampling (n = {SAMPLES})")
    for page in sorted(ranks):
        print(f"  {page}: {ranks[page]:.4f}")
    ranks = iterate_pagerank(corpus, DAMPING)
    print(f"PageRank Results from Iteration")
    for page in sorted(ranks):
        print(f"  {page}: {ranks[page]:.4f}")


def crawl(directory):
    """
    Parse a directory of HTML pages and check for links to other pages.
    Return a dictionary where each key is a page, and values are
    a list of all other pages in the corpus that are linked to by the page.
    """
    pages = dict()

    # Extract all links from HTML files
    for filename in os.listdir(directory):
        if not filename.endswith(".html"):
            continue
        with open(os.path.join(directory, filename)) as f:
            contents = f.read()
            links = re.findall(r"<a\s+(?:[^>]*?)href=\"([^\"]*)\"", contents)
            pages[filename] = set(links) - {filename}

    # Only include links to other pages in the corpus
    for filename in pages:
        pages[filename] = set(
            link for link in pages[filename]
            if link in pages
        )

    return pages


def transition_model(corpus, page, damping_factor):
    """
    Return a probability distribution over which page to visit next,
    given a current page.

    With probability `damping_factor`, choose a link at random
    linked to by `page`. With probability `1 - damping_factor`, choose
    a link at random chosen from all pages in the corpus.
    """

    dictionary = {}

    for site in corpus:
        dictionary[site] = 0

    for site in corpus[page]:
        dictionary[site] += damping_factor/(len(corpus[page]))

    for site in corpus:
        dictionary[site] += (1 - damping_factor) / len(corpus)

    return dictionary




def sample_pagerank(corpus, damping_factor, n):
    """
    Return PageRank values for each page by sampling `n` pages
    according to transition model, starting with a page at random.

    Return a dictionary where keys are page names, and values are
    their estimated PageRank value (a value between 0 and 1). All
    PageRank values should sum to 1.
    """

    dictionary = {}

    first_sample = random.choice(list(corpus.keys()))

    for site in list(corpus.keys()):
        dictionary[site] = 0

    dictionary[first_sample] = 1/n

    current_possibilities = transition_model(corpus, first_sample, damping_factor)

    for i in range(1 ,n):
        new_site = random.choices(list(current_possibilities.keys()), list(current_possibilities.values()), k = 1)
        dictionary[new_site[0]] += 1/n
        current_possibilities = transition_model(corpus, new_site[0], damping_factor)


    return dictionary


def iterate_pagerank(corpus, damping_factor):
    """
    Return PageRank values for each page by iteratively updating
    PageRank values until convergence.

    Return a dictionary where keys are page names, and values are
    their estimated PageRank value (a value between 0 and 1). All
    PageRank values should sum to 1.
    """
    dictionary = {}
    pages = list(corpus.keys())
    pages_length = len(corpus)

    iteration = True
    prob_1 = (1-damping_factor) / pages_length
    prob_2 = 0

    differnces = []

    for page in pages:
        dictionary[page] = 1 / pages_length

    while iteration:
        all_ranks = []
        for page in pages:
            all_links = []
            prob_2 = 0
            for p in pages:
                if page in corpus[p] or len(corpus[p]) == 0:
                    all_links.append(p)


            for link in all_links:
                if len(corpus[link]) != 0:
                    links_length = len(corpus[link])
                else:
                    links_length = len(corpus.keys())
                prob_2 += dictionary[link] / links_length

            prob_2 = damping_factor * prob_2
            total_rank = prob_1 + prob_2
            all_ranks.append(total_rank)
            differnces.append(abs(total_rank - dictionary[page]))

        if any(difference >= 0.001 for difference in differnces):
            differnces = []
            i = 0
            for page in corpus.keys():
                dictionary[page] = all_ranks[i]
                i += 1
        else:
            iteration = False

    return dictionary

if __name__ == "__main__":
    main()
