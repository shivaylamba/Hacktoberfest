"""
tfidf_logistic_regression.py
Author: Taha Zulfiquar
Description:
A simple text classification algorithm using TF-IDF vectorization and Logistic Regression.
This script demonstrates how to transform text data into numerical vectors and train a model
to classify text into categories based on content similarity.

The model will predict more accurately with larger dataset
"""

from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.linear_model import LogisticRegression
from sklearn.model_selection import train_test_split
from sklearn.metrics import classification_report

# Sample text data (balanced for demo)
texts = [
    "The cat sat on the mat",
    "Cats love sleeping on soft surfaces",
    "Dogs are loyal animals",
    "My puppy loves playing outside",
    "Dogs bark loudly at night",
    "The sun is bright today",
    "It is a sunny day outside",
    "I walk my dog every evening",
    "My dog loves running in the park",
    "Dogs enjoy walks in the evening",
    "Cats enjoy chasing mice",
    "The sunlight is warm and bright",
    "I love my doggy",
    "Cats love drinking milk",
    "The sun rises in the east",
    "the sun sets in the west"
]
labels = [0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0]  # 0 = cat/sun, 1 = dog

# TF-IDF vectorization
vectorizer = TfidfVectorizer(max_features=200)
X = vectorizer.fit_transform(texts)

# Split data with stratification to keep class balance
X_train, X_val, y_train, y_val = train_test_split(
    X, labels, test_size=0.3, random_state=42, stratify=labels
)

# Train logistic regression
model = LogisticRegression(max_iter=500)
model.fit(X_train, y_train)

# Evaluate model
y_pred = model.predict(X_val)
print("Classification Report:\n")
print(classification_report(y_val, y_pred))

# Example predictions
samples = [
    "My dog loves running in the park",
    "The cat is sleeping on the couch",
    "It is a bright sunny day outside",
    "i love to see my doggy sleep",
    "I use sunscreen to protect my skin from the sun"
]

for sample in samples:
    sample_vec = vectorizer.transform([sample])
    prediction = model.predict(sample_vec)[0]
    label_name = "dog" if prediction == 1 else "cat/sun"
    print(f"Prediction for sample '{sample}': {prediction} ({label_name})")
