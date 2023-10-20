import spacy
import random
from sklearn.feature_extraction.text import CountVectorizer, TfidfTransformer
from sklearn.model_selection import train_test_split
from sklearn.naive_bayes import MultinomialNB
from sklearn.metrics import accuracy_score, classification_report

# Load the spaCy English language model
nlp = spacy.load("en_core_web_sm")

# Load the IMDb movie reviews dataset
# You can download the dataset from: https://ai.stanford.edu/~amaas/data/sentiment/
# Organize the dataset into "pos" (positive) and "neg" (negative) folders
# Read and preprocess the reviews
reviews = []
labels = []

for sentiment in ["pos", "neg"]:
    for i in range(12500):
        with open(f"path/to/dataset/{sentiment}/{i}.txt", "r") as file:
            review = file.read()
            reviews.append(review)
            labels.append(1 if sentiment == "pos" else 0)

# Shuffle the data
data = list(zip(reviews, labels))
random.shuffle(data)
reviews, labels = zip(*data)

# Split the data into training and testing sets
X_train, X_test, y_train, y_test = train_test_split(reviews, labels, test_size=0.2, random_state=42)

# Text preprocessing and vectorization
vectorizer = CountVectorizer()
X_train_counts = vectorizer.fit_transform(X_train)
tfidf_transformer = TfidfTransformer()
X_train_tfidf = tfidf_transformer.fit_transform(X_train_counts)

# Train a Naive Bayes classifier
clf = MultinomialNB().fit(X_train_tfidf, y_train)

# Preprocess and classify test data
X_test_counts = vectorizer.transform(X_test)
X_test_tfidf = tfidf_transformer.transform(X_test_counts)
predicted = clf.predict(X_test_tfidf)

# Evaluate the model
accuracy = accuracy_score(y_test, predicted)
report = classification_report(y_test, predicted, target_names=["Negative", "Positive"])

print(f"Accuracy: {accuracy}")
print("Classification Report:")
print(report)