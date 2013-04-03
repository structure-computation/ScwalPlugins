im=imread('/home/ubuntu/Scwal/EcosystemScience/data.db/846930886');
disp('toto1')
filtersc = fspecial('sobel');
disp('toto2');
imf = imfilter(im, filtersc);
disp('toto3');
imwrite(imf,'/home/ubuntu/Scwal/EcosystemScience/data.db/846930886result.png');
