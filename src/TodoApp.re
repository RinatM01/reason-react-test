type todo = {
    id: string,
    text: string,
    isDone: bool
};

type state = array(todo);

type action = 
    |AddTodo(string)
    |ToggleTodo(string);

[@react.component]
let make = () => {
    let (name, setName) = React.useState(_ => "");
    // let (todos, setTodos) = React.useState(_ => [|{id: "1", text: "loool", isDone: true}|]);
    let (state, dispatch) = React.useReducer((state, action) => 
        switch (action) {
            | AddTodo(a) => Array.append([|{id: a, text: a, isDone: false}|], state)
            | ToggleTodo(s) => Array.map(todo => {
                switch (todo.id == s) {
                    | true => {...todo, isDone: !todo.isDone}
                    | false => todo
                }
            } ,state)
        }, [|{id: "1", text: "loool", isDone: true}|]
    );
    // let addTodo = _ => {
    //     setTodos(oldTodos => Array.append([|{id: name, text: name, isDone: false}|], oldTodos));
    //     setName(_ => "");
    // };
    // let markDone = id => {
    //     setTodos(oldTodos => Array.map(todo => {
    //         switch (todo.id == id) {
    //             | true => {...todo, isDone: !todo.isDone}
    //             | false => todo
    //         }
    //     }, oldTodos))
    // };
    <>
        <input type_="text" value=name onChange={event => {setName(_ => React.Event.Form.target(event)##value)}}/>
        <button onClick={_=> dispatch(AddTodo(name))}>
            {React.string("Add")}
        </button>
        {
            state
            ->Belt.Array.map(todo =>
                <Todo key={todo.id} id={todo.id} text={todo.text} isDone={todo.isDone} markDone={_=> dispatch(ToggleTodo(todo.id))}/>
            )
            ->React.array
    }
    </>
}