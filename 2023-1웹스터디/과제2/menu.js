const readline = require('readline').createInterface({
  input: process.stdin,
  output: process.stdout
});

const expenses = [];

function main() {
    console.log('\n<상세 내용>');
    console.log('(1) 지출 내역 입력');
    console.log('(2) 지출 내역 조회');
    console.log('(3) 지출 내역 수정');
    console.log('(4) 지출 내역 삭제');
    console.log('(5) 종료');
    readline.question('기능을 선택하세요: ', choice => {
        switch (choice) {
            case '1':
                addExpense();
                break;
            case '2':
                viewExpensesMenu();
                break;
            case '3':
                updateExpense();
                break;
            case '4':
                deleteExpense();
                break;
            case '5':
                readline.close();
                break;
            default:
                console.log('올바른 선택지를 입력하세요.');
                main();
        }
    });
}

function addExpense() {
    readline.question('지출한 날짜를 입력하세요 (YYYY-MM-DD): ', date => {
        readline.question('지출 카테고리를 입력하세요: ', category => {
            readline.question('상세 내역을 입력하세요: ', details => {
                readline.question('지출 금액을 입력하세요: ', amount => {
                    expenses.push({
                        date,
                        category,
                        details,
                        amount: parseFloat(amount)
                    });
                    console.log('지출 내역이 성공적으로 기록되었습니다.');
                    main();
                });
            });
        });
    });
}

function viewExpensesMenu() {
    console.log('\n<지출 내역 조회>');
    console.log('(1) 전체 내역 조회');
    console.log('(2) 카테고리별 조회');
    console.log('(3) 날짜별 조회');
    console.log('(4) 상세 내역 검색');
    console.log('(5) 뒤로 가기');
    readline.question('조회 방식을 선택하세요: ', choice => {
        switch (choice) {
            case '1':
                viewAllExpenses();
                break;
            case '2':
                viewExpensesByCategory();
                break;
            case '3':
                searchExpensesByDate();
                break;
            case '4':
                searchExpensesByDetails();
                break;
            case '5':
                main();
                break;
            default:
                console.log('올바른 선택지를 입력하세요.');
                viewExpensesMenu();
        }
    });
}


function viewAllExpenses() {
  console.log('<전체 내역 조회>');
  expenses.forEach((expense, index) => {
      console.log(`[${index + 1}] ${JSON.stringify(expense)}`);
  });
  viewExpensesMenu();
}

function viewExpensesByCategory() {
  readline.question('조회할 카테고리를 입력하세요: ', category => {
      const filteredExpenses = expenses.filter(expense => expense.category === category);
      console.log(`<${category} 카테고리 내역 조회>`);
      filteredExpenses.forEach((expense, index) => {
          console.log(`[${index + 1}] ${JSON.stringify(expense)}`);
      });
      viewExpensesMenu();
  });
}

function searchExpensesByDate() {
  readline.question('검색할 날짜를 입력하세요 (YYYY-MM-DD): ', date => {
      const filteredExpenses = expenses.filter(expense => expense.date === date);
      console.log(`<${date} 날짜 검색 결과>`);
      filteredExpenses.forEach((expense, index) => {
          console.log(`[${index + 1}] ${JSON.stringify(expense)}`);
      });
      viewExpensesMenu();
  });
}

function searchExpensesByDetails() {
  readline.question('검색할 상세 내역을 입력하세요: ', details => {
      const filteredExpenses = expenses.filter(expense => expense.details.includes(details));
      console.log(`<${details} 상세 내역 검색 결과>`);
      filteredExpenses.forEach((expense, index) => {
          console.log(`[${index + 1}] ${JSON.stringify(expense)}`);
      });
      viewExpensesMenu();
  });
}

function updateExpense() {
  readline.question('수정할 지출 내역의 인덱스를 입력하세요: ', index => {
      const expense = expenses[index - 1];
      if (!expense) {
          console.log('올바른 인덱스를 입력하세요.');
          updateExpense();
          return;
      }
      readline.question(`수정된 날짜를 입력하세요 (이전 값: ${expense.date}): `, date => {
          readline.question(`수정된 카테고리를 입력하세요 (이전 값: ${expense.category}): `, category => {
              readline.question(`수정된 상세 내역을 입력하세요 (이전 값: ${expense.details}): `, details => {
                  readline.question(`수정된 금액을 입력하세요 (이전 값: ${expense.amount}): `, amount => {
                      expenses[index - 1] = {
                          date: date || expense.date,
                          category: category || expense.category,
                          details: details || expense.details,
                          amount: amount ? parseFloat(amount) : expense.amount
                      };
                      console.log('지출 내역이 성공적으로 수정되었습니다.');
                      main();
                  });
              });
          });
      });
  });
}

function deleteExpense() {
  readline.question('삭제할 지출 내역의 인덱스를 입력하세요: ', index => {
      if (index >= 1 && index <= expenses.length) {
          expenses.splice(index - 1, 1);
          console.log('지출 내역이 성공적으로 삭제되었습니다.');
      } else {
          console.log('올바른 인덱스를 입력하세요.');
          deleteExpense();
      }
      main();
  });
}

main();
