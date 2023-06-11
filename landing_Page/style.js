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

const main = () => {


  // handle search event
  const searchOpenBtn = document.querySelector(".search-btn");
  searchOpenBtn.addEventListener("click",() => {
    const checkBoxOpenTag = document.querySelector(".checkbox-search-open")
    if(checkBoxOpenTag.checked ) {
      document.querySelector(".modal-search-tablet").style.display ="block";
      document.querySelector('.check-search-btn').checked = false;
    }
  })
  const checkCloseSearchTag = document.querySelector(".check-search-btn")
  checkCloseSearchTag.addEventListener("click", () => {
    if(checkCloseSearchTag.checked ) {
      document.querySelector(".modal-search-tablet").style.display ="none";
      document.querySelector(".search-btn").checked = false;
    }
  })
}
// window.addEventListener('scroll', function() {
//   const progressContainer = document.querySelector('.progress-container');
//   const progressBar = document.querySelector('.progress-bar');

//   const scrollTop = document.documentElement.scrollTop || document.body.scrollTop;
//   const scrollHeight = document.documentElement.scrollHeight || document.body.scrollHeight;
//   const windowHeight = document.documentElement.clientHeight || window.innerHeight;

//   const progress = (scrollTop / (scrollHeight - windowHeight)) * 100;
//   progressBar.style.height = progress + '%';

//   // Tính toán vị trí của progressContainer
//   const containerHeight = progressContainer.offsetHeight;
//   const maxContainerScroll = scrollHeight - windowHeight - containerHeight;
//   const containerScroll = (progress * maxContainerScroll) / 100;
//   progressContainer.style.top = containerScroll + 'px';
// });

// window.addEventListener('scroll', updateProgressBar);

main();

