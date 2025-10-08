# word_frequency_csv.py
import pandas as pd
import re
from collections import Counter

# Sample text for analysis (you can replace with any input text)
text = """
Data analysis is essential in today's world.
Analyzing data helps uncover insights and make better decisions.
Python makes data analysis simple and powerful.
"""

# Clean text: remove punctuation, make lowercase
clean_text = re.sub(r'[^A-Za-z\s]', '', text).lower()

# Split into words
words = clean_text.split()

# Count word frequencies
word_counts = Counter(words)

# Convert to DataFrame
df = pd.DataFrame(word_counts.items(), columns=["Word", "Frequency"])
df = df.sort_values(by="Frequency", ascending=False)

# Display top words
print("📊 Word Frequency Analysis:")
print(df.head(10))

# Save to CSV
df.to_csv("word_frequency.csv", index=False)
print("\n✅ Results saved to word_frequency.csv")
