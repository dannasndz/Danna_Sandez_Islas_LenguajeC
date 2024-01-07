import cv2
import numpy as np

imagen=cv2.imread("opencv//spotify.png",0)
cv2.imshow("imagen abierta",imagen)

cv2.waitKey(0)
cv2.destroyAllWindows()