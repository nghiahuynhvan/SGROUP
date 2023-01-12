const progressBars = document.querySelectorAll('.progressbar__time');
let i = 0;
setInterval(()=>{
  progressBars[i].classList.remove("active");
  i = (i + 1) % progressBars.length;
  progressBars[i].classList.add("active");
},5000)
// Slideshow auto // 
const cardCarousel = document.querySelector(".card");
const cardImg = document.querySelectorAll(".card-img__image");
let current = 0;
cardImg.forEach((img, index) => {
  if (index !== current) {
    img.style.opacity = "0";
  }
});
setInterval(() => {
  cardImg[current].style.opacity = "0";
  current = (current + 1) % cardImg.length;
  cardImg[current].style.opacity = "1";
}, 5000);
