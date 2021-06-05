import numpy as np
from sklearn.metrics import roc_curve
import matplotlib.pyplot as plt

def my_roc_curve(arr):
    fpr = {}
    tpr = {}
    thresh = {}
    y_labels = [i for i in range(40)]
    for i in range(40):
        a = arr[i, :-1]
        a = a.reshape((a.shape[0], 1))
        fpr[i], tpr[i], thresh[i] = roc_curve(y_labels, a, pos_label=arr[i, -1])

    for i in range(40):
        plt.plot(fpr[i], tpr[i], linestyle='--', label='Class {} vs Rest'.format(i))

    plt.title('Multiclass ROC curve')
    plt.xlabel('False Positive Rate')
    plt.ylabel('True Positive rate')
    plt.legend(loc='upper right', prop={'size': 4})
    plt.savefig('multi', dpi=300)


if __name__ == '__main__':
    arr = np.loadtxt('data.txt', delimiter='\t')
    print(arr.shape)
    my_roc_curve(arr)
