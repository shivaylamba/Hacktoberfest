from skimage.restoration import denoise_nl_means, estimate_sigma
from skimage import img_as_float, img_as_ubyte
from skimage import io
import numpy as np

image = img_as_float(io.imread("room_noisy.jpg")).astype(np.float32)

sigma_est = np.mean(estimate_sigma(image,multichannel=True))

print("estimated noise standard deviation= {}".format(sigma_est))

patch_kw = dict(patch_size=10,patch_distance=3,multichannel=True)

denoise_img = denoise_nl_means(image, h=1.15 * sigma_est, fast_mode=False, **patch_kw)

denoise_img_as_8byte = img_as_ubyte(denoise_img)

io.imsave("NLM.jpg", denoise_img_as_8byte)