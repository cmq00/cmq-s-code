from PIL import Image
from torchvision.transforms import ToTensor,ToPILImage
to_tensor = ToTensor()
to_pil = ToPILImage()
lena = Image.open('imgs/lena.png')
lena
