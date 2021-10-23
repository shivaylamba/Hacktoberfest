from sklearn.cluster import KMeans
import pandas as pd

#reading the csv file having fees and experience as two columns
df = pd.read_csv('file_name.csv', sep=',', header=None)

#checking the values read in a numpy array
print(df.values)

# making two cluster for k-means
kmeans = KMeans(n_clusters=2)

#passing the cluster values to the k-means
kmeans.fit(df.values)

#checking the centres of the two clusters formed
print(kmeans.cluster_centers_)

#checking the cluster that is formed
#here 1 signifies that the element is present in the cluster and 0 specifies it is not.
print(kmeans.labels_)
