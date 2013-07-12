im=imread('/home/jbellec/code_dev_scwal/EcosystemScience/data.db/524872353');
filtersc = fspecial('sobel');
imf = imfilter(im, filtersc);
imwrite(imf,'/home/jbellec/code_dev_scwal/EcosystemScience/data.db/524872353result.png');
