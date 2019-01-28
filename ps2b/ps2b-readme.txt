uml Computing IV
Jingxian Shi
ps2b

The program takes 5 arguments: executable, input image, output image, seed and tap position. the main program opens two windows that shows the original image and the encrypted image. The encryption is done by xoring the color of each pixel of the image with the generated integer from the seed using the generate function in the LFSR class. If run the encryption process again on the encrypted image, the image will transform back to original because the reverse of xor operation is xor itself.
