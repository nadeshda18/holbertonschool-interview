import requests


def count_words(subreddit, word_list, after=None, counts=None):
    """
    Queries the Reddit API, parses the titles of hot articles, and counts
    occurrences of given keywords (case-insensitive).
    """
    if counts is None:
        counts = {word.lower(): 0 for word in word_list}

    url = f"https://www.reddit.com/r/{subreddit}/hot.json"
    headers = {"User-Agent": "Mozilla/5.0"}
    params = {"limit": 100, "after": after}

    response = requests.get(url, headers=headers,
                            params=params, allow_redirects=False)

    if response.status_code != 200:
        return

    data = response.json().get("data")
    if not data:
        return

    # Parse titles and count occurrences of keywords
    for post in data.get("children", []):
        title = post.get("data", {}).get("title", "").lower()
        for word in counts.keys():
            counts[word] += title.split().count(word)

    # Check if there are more pages to fetch
    after = data.get("after")
    if after:
        count_words(subreddit, word_list, after, counts)
    else:
        # Sort and print results
        sorted_counts = sorted(
            [(word, count) for word, count in counts.items() if count > 0],
            key=lambda x: (-x[1], x[0])
        )
        for word, count in sorted_counts:
            print(f"{word}: {count}")
